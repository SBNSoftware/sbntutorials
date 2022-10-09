#pragma once 

#include "sbnana/CAFAna/Core/SpectrumLoader.h"
#include "sbnana/CAFAna/Core/Spectrum.h"

#include "helper_nuSel.h"

#include "TCanvas.h"
#include "TFile.h"
#include "TTreeReader.h"
#include "TH1.h"
#include "TH2.h"
#include "TLegend.h"
#include "TPaveText.h"
#include "TStyle.h"

using namespace ana;

void nuSel(){

  //
  // Environment variables and wildcards work as arguments to
  // SpectrumLoader. As do SAM datasets.
  const std::string fdata = "/icarus/data/users/howard/Run7924_and_7926/Set*/*flat*.root"; 


    // Source of events
  SpectrumLoader loader(fdata);
  
    // Spectrum

//  Spectrum sevts_Selection_all ("evts", kEvtBinning, loader, kEvt, kNumuCC_SelectionSpillCut);
  Spectrum sevts_Selection_all ("evts", kEvtBinning, loader, kEvt, kNumuCC_SelectionSpillCut && krun_SpillCut);

  Spectrum stdy     (loader,     axtdy,   krun_SpillCut,  kNoCut);
  Spectrum stdy_all (loader,     axtdy,   krun_SpillCut,  kNumuCC_Selection);
  Spectrum stkl     (loader,     axtkl,   krun_SpillCut,  kNoCut);
  Spectrum stkl_all (loader,     axtkl,   krun_SpillCut,  kNumuCC_Selection);

  
  // actually make the spectra
  loader.Go();

    // Histograms  

  stdy.OverridePOT(1);
  stdy_all.OverridePOT(1);
  stkl.OverridePOT(1);
  stkl_all.OverridePOT(1);

  TH1* htdy     = stdy.ToTH1(stdy.POT(), kBlue+2);
  TH1* htdy_all = stdy_all.ToTH1(stdy_all.POT(), kRed+1);
  TH1* htkl     = stkl.ToTH1(stkl.POT(), kBlue+2);
  TH1* htkl_all = stkl_all.ToTH1(stkl_all.POT(), kRed+1);

  htdy -> SetTitle("");
  htdy -> GetYaxis()->SetTitle("Slices");
  htdy -> GetXaxis()->SetTitle("Y direction of CR longest");
  htdy -> GetYaxis()->CenterTitle();
  htdy -> GetXaxis()->CenterTitle();

  htkl -> SetTitle("");
  htkl -> GetYaxis()->SetTitle("Slices");
  htkl -> GetXaxis()->SetTitle("Track Length (cm)");
  htkl -> GetYaxis()->CenterTitle();
  htkl -> GetXaxis()->CenterTitle();

  TLegend *leg = new TLegend(0.5, 0.60, 0.85, 0.85, NULL,"brNDC");
  leg -> SetFillStyle(0);
  leg -> SetTextSize(0.04);
  leg -> AddEntry(htdy,       "NO cuts",  "l");
  leg -> AddEntry(htdy_all,   "With cuts",   "l");


  TCanvas* ctdy = new TCanvas("ctdy", "");
  htdy     -> GetYaxis() -> SetRangeUser(0.,1.3 * htdy -> GetMaximum());
  htdy     -> Draw("hist");
  htdy_all -> Draw("hist same");
  leg -> Draw("same");  
  ctdy -> Print("tdy_distributions.png");
    
  TCanvas* ctkl = new TCanvas("ctkl", "");
  htkl     -> GetYaxis() -> SetRangeUser(0.,1.3 * htkl -> GetMaximum());
  htkl     -> Draw("hist");
  htkl_all -> Draw("hist same");
  leg -> Draw("same");  
  ctkl -> Print("tkl_distributions.png");
    

}  
