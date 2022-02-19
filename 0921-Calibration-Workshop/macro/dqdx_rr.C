#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

void dqdx_rr() {
   // Create a histogram for the values we read.
   TH2F *myHist = new TH2F("dqdx_rr","dqdx vs residual range: West Cryostat", 50, 0., 150., 100, 400., 2000.);
   myHist->GetXaxis()->SetTitle("residual range in cm");
   myHist->GetYaxis()->SetTitle("dqdx in ADC/cm");

   gStyle->SetOptStat(0);
   // Open the file containing the tree.
   TFile *myFile = TFile::Open("/icarus/data/users/obitter/CalibrationWS21/Supplemental-gen_20210909T075432-G4_20210909T081124-DetSim_20210909T095200-MCstage0_20210909T104941-MCstage1.root");
   if (!myFile || myFile->IsZombie()) {
      return;
   }

   // NOTE: Only for ICARUS MC!
   //
   // Process data from tracks in the east cryostat
   //
   // If running on SBND, change caloskimE -> caloskim (only one cryostat)
   TTreeReader myReader("caloskimE/TrackCaloSkim", myFile);

   // Variables we are going to read
   TTreeReaderValue<int> selected(myReader, "trk.selected");

   TTreeReaderArray<float> dqdx(myReader, "trk.hits2.dqdx"); // hits on plane 2 (Collection)
   TTreeReaderArray<float> rr(myReader, "trk.hits2.rr"); // hits on plane 2 (Collection)

   // Loop over all entries of the TTree
   while (myReader.Next()) {
      if (*selected == 0) { // Tracks selected as stopping
          for (unsigned i = 0; i < dqdx.GetSize(); i++) {
              myHist->Fill(rr[i], dqdx[i]);
          }
      }
   }
   myHist->Draw("COLZ");
}
