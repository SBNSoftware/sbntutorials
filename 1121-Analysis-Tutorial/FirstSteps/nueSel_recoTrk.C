#pragma once 

#include "sbnana/CAFAna/Core/SpectrumLoader.h"
#include "sbnana/CAFAna/Core/Spectrum.h"
#include "sbnana/CAFAna/Core/Binning.h"
#include "sbnana/CAFAna/Core/Cut.h"
#include "sbnana/CAFAna/StandardRecord/Proxy/SRProxy.h"

#include "sbnana/SBNAna/Vars/Binnings.h"
#include "sbnana/SBNAna/Vars/NueVars.h"
#include "sbnana/SBNAna/Vars/TruthVars.h"
#include "sbnana/SBNAna/Vars/Vars.h"
#include "sbnana/SBNAna/Cuts/Cuts.h"
#include "sbnana/SBNAna/Cuts/NueCuts.h"
#include "sbnana/SBNAna/Cuts/TruthCuts.h"

#include "TCanvas.h"
#include "TFile.h"
#include "TTreeReader.h"
#include "TH1.h"
#include "TH2.h"
#include "TLegend.h"
#include "TPaveText.h"
#include "TStyle.h"

using namespace ana;

    // Cuts 

  const Cut kNueCC      = kIsNue && !kIsNC;
  const Cut kThisCosmic = !kHasNu;
  const Cut kNueTrkCut  = kNueTrackLenCut; 

void nueSel_recoTrk(){

  const std::string fname = "/icarus/data/users/lupis/work/icaruscode/tutorialNov2021/icarus_numi_offaxis_nue_cosmics.flatcaf.root";

    // Source of events
  SpectrumLoader loader(fname);
  
  double POT = 6E20;
  
    // Binning
  const Binning kLengthBinning = Binning::Simple(20,0.,200.);
  
    // HistAxis 
  const HistAxis axtrkl("Track length (cm)", kLengthBinning, kLongestTrackLength);

    // Spectrum
  Spectrum strkl_nue  (loader, axtrkl, kNueCC);
  Spectrum strkl_cos  (loader, axtrkl, kThisCosmic);
  
  Spectrum strkl_tlcut_nue (loader, axtrkl, kNueTrkCut && kNueCC);
  Spectrum strkl_tlcut_cos (loader, axtrkl, kNueTrkCut && kThisCosmic);
  
  
    // actually make the spectra
  loader.Go();

    // Make histos
  strkl_nue.OverridePOT(1);
  strkl_cos.OverridePOT(1);
  strkl_tlcut_nue.OverridePOT(1);
  strkl_tlcut_cos.OverridePOT(1);

  TH1* htrkl_nue = strkl_nue.ToTH1(strkl_nue.POT(), kBlue-7);
  TH1* htrkl_cos = strkl_cos.ToTH1(strkl_cos.POT(), kGray+2);
  TH1* htrkl_tlcut_nue = strkl_tlcut_nue.ToTH1(strkl_tlcut_nue.POT(), kBlue-7);
  TH1* htrkl_tlcut_cos = strkl_tlcut_cos.ToTH1(strkl_tlcut_cos.POT(), kGray+2);

  htrkl_nue -> GetYaxis()->SetTitle("Slices");
  htrkl_nue -> GetYaxis()->CenterTitle();
  htrkl_nue -> GetXaxis()->CenterTitle();

  htrkl_cos -> GetYaxis()->SetTitle("Slices");
  htrkl_cos -> GetYaxis()->CenterTitle();
  htrkl_cos -> GetXaxis()->CenterTitle();

  htrkl_tlcut_nue -> GetYaxis()->SetTitle("Slices");
  htrkl_tlcut_nue -> GetYaxis()->CenterTitle();
  htrkl_tlcut_nue -> GetXaxis()->CenterTitle();

  htrkl_tlcut_cos -> GetYaxis()->SetTitle("Slices");
  htrkl_tlcut_cos -> GetYaxis()->CenterTitle();
  htrkl_tlcut_cos -> GetXaxis()->CenterTitle();


    // Save histos into a ROOT file
  TFile f("track_len.root", "RECREATE");
  htrkl_nue -> Write("trkl_nue");
  htrkl_cos -> Write("trkl_cos");
  htrkl_tlcut_nue -> Write("trkl_tlcut_nue");
  htrkl_tlcut_cos -> Write("trkl_tlcut_cos");
  
  
    // Make plots
  TLegend *l = new TLegend(0.60, 0.60, 0.85, 0.85, NULL,"brNDC");
  l->SetFillStyle(0);
  l->SetTextSize(0.04);
  l->AddEntry(htrkl_nue,    "#nu_{e} CC",           "l");
  l->AddEntry(htrkl_cos,    "Cosmics out time",     "l");


  TCanvas* c = new TCanvas("c", "");
  htrkl_cos -> GetYaxis()->SetRangeUser(0.,1.3 * htrkl_cos->GetMaximum());
  htrkl_cos -> Draw("hist");
  htrkl_nue -> Draw("hist same");
  l -> Draw("same");
  c -> Print("trkLen_nocuts.png");

  TCanvas* c_tlcut = new TCanvas("c_tlcut", "");
  htrkl_tlcut_cos -> GetYaxis()->SetRangeUser(0.,1.3 * htrkl_tlcut_cos->GetMaximum());
  htrkl_tlcut_cos -> Draw("hist");
  htrkl_tlcut_nue -> Draw("hist same");
  l -> Draw("same");
  c_tlcut -> Print("trkLen_tlcut.png");
 
}  
