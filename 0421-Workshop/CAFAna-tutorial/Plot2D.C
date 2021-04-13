// Make a plot with cuts
#include "sbnana/CAFAna/Core/Binning.h"
#include "sbnana/CAFAna/Core/Spectrum.h"
#include "sbnana/CAFAna/Core/SpectrumLoader.h"

using namespace ana;

#include "sbnana/CAFAna/StandardRecord/Proxy/SRProxy.h"

#include "TCanvas.h"
#include "TH1.h"
#include "TH2.h"
#include "TLegend.h"

// ---- VARS -----
// A Var returns a number per slice, a.k.a. variables to plot
const Var kNTrk = SIMPLEVAR(reco.ntrk);
const Var kNShw = SIMPLEVAR(reco.nshw);

// Define some cuts based on the Vars
const Cut kNTrkCut = kNTrk > 2;
const Cut kNShwCut = kNShw > 2;

// We can then combine the cuts together
// This can be used to combine many cuts together
const Cut kNTrkShwCut = kNTrkCut && kNShwCut;

// Alternatively we could use or logic
// const Cut = kNTrkCut || kNShwCut;

void Plot2D(const std::string inputName = "/pnfs/sbnd/persistent/sbndpro/mcp/mc/workshop/SBNWorkshop0421/prodoverlay_corsika_cosmics_proton_genie_nu_spill_gsimple-configf-v1_tpc/v09_19_00_01/caf/flat_caf_0-9f00feff-e742-419d-9856-9fe7428b93a9.root")
{
  // Environment variables and wildcards work as arguments to
  // SpectrumLoader. As do SAM datasets.
  // Source of events
  SpectrumLoader loader(inputName);

  // ---- SPECTRA -----
  // A spectrum is a histogram with associated POT information
  const Binning binsN = Binning::Simple(10, 0, 10);

  //HistAxis( <Title>,Binning,Var)
  const HistAxis axNTrk("Number of Tracks", binsN, kNTrk);
  const HistAxis axNShw("Number of Tracks", binsN, kNShw);

  //Spectrum(Spectrumloader,HistAxis,Cut)
  Spectrum sNTrk(loader, axNTrk, kNoCut);
  Spectrum sNShw(loader, axNShw, kNoCut);

  //Spectrum(Spectrumloader ,HistAxisX HistAxisY, SpillCut, Cut)
  Spectrum sNTrkShw(loader, axNTrk, axNShw, kNoSpillCut, kNoCut);
  Spectrum sNTrkShwCut(loader, axNTrk, axNShw, kNoSpillCut, kNTrkShwCut);

  // This is the call that actually fills in the spectrum
  loader.Go();

  // ---- DRAW -----
  // For plotting purposes we can convert spectra to a TH1
  TCanvas* c1 = new TCanvas("c1", "c1");
  TH1* hNTrk = sNTrk.ToTH1(6.6e20);
  TH1* hNShw = sNShw.ToTH1(6.6e20);
  hNTrk->Draw("hist");
  hNShw->SetLineColor(kBlue + 2);
  hNShw->Draw("hist same");

  //Drawing a legend because we are not hobos
  TLegend* leg = new TLegend(0.6, 0.7, 0.85, 0.8);
  leg->AddEntry(hNTrk, "Num Tracks", "l");
  leg->AddEntry(hNShw, "Num Shower", "l");
  leg->Draw();
  c1->Print("NTrkShw.png");

  // Create a 2D plot
  TCanvas* c2 = new TCanvas("c2", "c2");
  TH2* hNTrkShw = sNTrkShw.ToTH2(6.6e20);
  hNTrkShw->Draw("colz");
  c2->Print("NtrkShw2D.png");

  // Create a 2D plot with a Cut
  TCanvas* c3 = new TCanvas("c3", "c3");
  TH2* hNTrkShwCut = sNTrkShwCut.ToTH2(6.6e20);
  hNTrkShwCut->Draw("colz");
  c3->Print("NtrkShw2DCut.png");
}
