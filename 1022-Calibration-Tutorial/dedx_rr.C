#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

#include "wda.h"

struct TPCData {
  double EE;
  double EW;
  double WE;
  double WW;

  double atTPC(int cryo, int tpc) { // 0 is E, 1 is W
    if (cryo == 0 && tpc == 0) return EE;
    if (cryo == 0 && tpc == 1) return EW;
    if (cryo == 1 && tpc == 0) return WE;
    if (cryo == 1 && tpc == 1) return WW;

    return -1.;
  }
};

TPCData GetTPCData(std::string url, unsigned value_index) {
  unsigned TIMEOUT = 200;

  int error = 0;
  Dataset d = getDataWithTimeout(url.c_str(), "", TIMEOUT, &error);

  assert(!error);

  TPCData ret;
  for (unsigned row = 4; row < 8; row++) {
    Tuple tup = getTuple(d, row);

    int err = 0;
    // Get the channel number
    int ch = getLongValue(tup, 0, &err);
    assert(!err);

    double gain = getDoubleValue(tup, value_index, &err);
    assert(!err);

    if (ch == 0) ret.EE = gain;
    if (ch == 1) ret.EW = gain;
    if (ch == 2) ret.WE = gain;
    if (ch == 3) ret.WW = gain;
  }

  return ret;
}

TPCData GetLifetimes(unsigned run) {
  std::string URL = "https://dbdata0vm.fnal.gov:9443/icarus_con_prod/app/data?f=tpc_elifetime_data&t=";
  return GetTPCData(URL + std::to_string(run), 1);
}

TPCData GetGains(unsigned run) {
  std::string URL = "https://dbdata0vm.fnal.gov:9443/icarus_con_prod/app/data?f=tpc_dqdxcalibration_data&t=";
  return GetTPCData(URL + std::to_string(run), 2);
}

struct YZScales {
  struct ScaleBin {
    int itpc;
    double ylo;
    double yhi;
    double zlo;
    double zhi;
    
    double scale;
  };

  std::vector<ScaleBin> bins;

  double Scale(double y, double z, int itpc) {
    for (const ScaleBin &b: bins) {
      if (itpc == b.itpc &&
          (y >= b.ylo) && (y < b.yhi) &&
          (z >= b.zlo) && (z < b.zhi)) {
        return b.scale;
      }
    }
    return -1.;
  }
};

YZScales GetYZScales(unsigned run) {
  std::string url = "https://dbdata0vm.fnal.gov:9443/icarus_con_prod/app/data?f=test_tpc_yz_correction_data&t=" + std::to_string(run);
  int error = 0;
  unsigned TIMEOUT = 200;

  Dataset d = getDataWithTimeout(url.c_str(), "", TIMEOUT, &error);

  assert(!error);

  YZScales ret;

  int n_tuple = getNtuples(d);
  for (unsigned row = 4; row < (unsigned)n_tuple; row++) {
    Tuple tup = getTuple(d, row);

    int err = 0;
    // Get the TPC value
    char tpcbuf[10];
    int strl = getStringValue(tup, 1, tpcbuf, 10, &err);
    (void) strl;
    assert(!err);
    int itpc = -1;
    std::string tpcname(tpcbuf);
    if (tpcname == "EE") itpc = 0;
    else if (tpcname == "EW") itpc = 1;
    else if (tpcname == "WE") itpc = 2;
    else if (tpcname == "WW") itpc = 3;

    double ylo = getDoubleValue(tup, 8, &err);
    assert(!err);
    double yhi = getDoubleValue(tup, 9, &err);
    assert(!err);
    double zlo = getDoubleValue(tup, 10, &err);
    assert(!err);
    double zhi = getDoubleValue(tup, 11, &err);
    assert(!err);
    double scale = getDoubleValue(tup, 4, &err);
    assert(!err);

    YZScales::ScaleBin bin;
    bin.ylo = ylo;
    bin.yhi = yhi;
    bin.zlo = zlo;
    bin.zhi = zhi;
    bin.itpc = itpc;
    bin.scale = scale;

    ret.bins.push_back(bin);
  }


  return ret;
}

// Constants
static double TANODE = 850; // ticks
static double TICK_PERIOD = 400; // ns

static double A = 0.948; // from calibration fit
static double B = 0.212; // from calibration fit
static double E = 0.493; // kV/cm

double derecombine(double dQdx) {
  double LAr_density_gmL = 1.389875; // g/mL (m is for milli for those not in the know)
  double Wion = 1e3 / 4.237e7;
  double alpha = A;
  double beta = B / (LAr_density_gmL * E);
  
  double dEdx = (exp(dQdx*Wion*beta) - alpha) / beta;
  
  return dEdx;
}

void dedx_rr() {
   // Create a histogram for the values we read.
   TH2F *myHist = new TH2F("dedx_rr","dedx vs residual range: East Cryostat", 50, 0., 150., 91, 1., 10.);
   myHist->GetXaxis()->SetTitle("residual range [cm]");
   myHist->GetYaxis()->SetTitle("dE/dx [MeV/cm]");

   gStyle->SetOptStat(0);
   // Open the file containing the tree.
   TFile *myFile = TFile::Open("/pnfs/icarus/persistent/calibration/calib_ntuples/data/v09_37_02_09/offbeambnbmajority/run/85/05/hist_data_dl9_fstrmOffBeamBNBMAJORITY_run8505_45_20220619T070132_20220701T100443-stage0_20220703T111223_stage1-6e16ea52-b7f1-4ebf-9f26-3cea1659061f.root");
   if (!myFile || myFile->IsZombie()) {
      return;
   }

   // Process data from tracks in the east cryostat
   TTreeReader myReader("caloskimE/TrackCaloSkim", myFile);
   int cryo = 0; // EAST

   // Variables we are going to read
   TTreeReaderValue<int> selected(myReader, "trk.selected");
   
   TTreeReaderArray<float> dqdxs(myReader, "trk.hits2.dqdx"); // hits on plane 2 (Collection)
   TTreeReaderArray<float> rrs(myReader, "trk.hits2.rr"); // hits on plane 2 (Collection)
   TTreeReaderArray<float> xs(myReader, "trk.hits2.h.sp.x");
   TTreeReaderArray<float> ys(myReader, "trk.hits2.h.sp.y");
   TTreeReaderArray<float> zs(myReader, "trk.hits2.h.sp.z");
   TTreeReaderArray<float> ts(myReader, "trk.hits2.h.time");
   TTreeReaderArray<unsigned short> tpcs(myReader, "trk.hits2.h.tpc");
   TTreeReaderArray<bool> ontraj(myReader, "trk.hits2.ontraj");

   // Loop over all entries of the TTree
   while (myReader.Next()) {
      // querrying the database is slow -- might want to only want to do this once
      TPCData thisLifetimes = GetLifetimes(*run);
      TPCData thisGains = GetGains(*run);
      YZScales thisScales = GetYZScales(*run);

      if (*selected == 0) { // Tracks selected as stopping
          for (unsigned i = 0; i < dqdxs.GetSize(); i++) {
              if (!ontraj[i]) continue;

              double dqdx = dqdxs[i];
              double rr = rrs[i];
              double y = ys[i];
              double z = zs[i];
              int itpc = cryo*2 + tpcs[i]/2;
              double thit = (ts[i] * TICK_PERIOD - *t0 - TANODE*TICK_PERIOD) / 1000.;

              double tau = thisLifetimes.atTPC(cryo, tpcs[i]);

              double t_corr = exp(thit/tau);
              double yz_corr = thisScales.Scale(y, z, itpc);
              double gain = thisGains.atTPC(cryo, tpcs[i]);
              double dqdx_nelec = (dqdx*t_corr / yz_corr) * gain;

              double dedx = derecombine(dqdx_nelec);

              myHist->Fill(rr, dedx);
          }
      }
   }
   myHist->Draw("COLZ");
}
