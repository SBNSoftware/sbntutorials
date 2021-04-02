// Make a plot with cuts
#include "CAFAna/Core/Binning.h"
#include "CAFAna/Core/Spectrum.h"
#include "CAFAna/Core/SpectrumLoader.h"

using namespace ana;

#include "StandardRecord/Proxy/SRProxy.h"

#include "TCanvas.h"
#include "TH1.h"
#include "TLegend.h"

// ---- VARS -----
// A Var returns a number per slice, a.k.a. variables to plot
const SpillVar kNSlc([](const caf::SRSpillProxy* spill) -> int {
  return spill->nslc;
});

// ---- CUTS -----
// A Cut returns a boolean per slice
const SpillCut kSlcCut10([](const caf::SRSpillProxy* spill) {
  return spill->nslc >= 10;
});

// We can also create SpillCuts from applying regular Cuts to the slices in  aspill
const Cut kNuSlc([](const caf::SRSliceProxy* slc) {
  return slc->is_clear_cosmic == 0;
});

const SpillCut kNuSlcCut3([](const caf::SRSpillProxy* spill) {
  unsigned int counter(0);
  for (const caf::SRSliceProxy& slc : spill->slc) {
    if (kNuSlc(&slc))
      ++counter;
  }
  return counter >= 3;
});

void Spill(const std::string inputName = "/pnfs/sbnd/persistent/sbndpro/mcp/mc/workshop/SBNWorkshop0421/prodoverlay_corsika_cosmics_proton_genie_nu_spill_gsimple-configf-v1_tpc/v09_19_00_01/caf/flat_caf_0-9f00feff-e742-419d-9856-9fe7428b93a9.root")
{
  // Environment variables and wildcards work as arguments to
  // SpectrumLoader. As do SAM datasets.
  // Source of events
  SpectrumLoader loader(inputName);

  // ---- SPECTRA -----
  // A spectrum is a histogram with associated POT information
  const Binning binsN = Binning::Simple(20, 0, 40);

  // Spectrum(Spectrumloader, HistAxis, Cut)
  Spectrum sNSlc("sNSlc", binsN, loader, kNSlc, kNoSpillCut);
  Spectrum sNSlc10("sNSlc10", binsN, loader, kNSlc, kSlcCut10);
  Spectrum sNNuSlc3("sNNuSlc3", binsN, loader, kNSlc, kNuSlcCut3);

  // This is the call that actually fills in the spectrum
  loader.Go();

  // ---- DRAW -----
  // For plotting purposes we can convert spectra to a TH1
  TCanvas* c1 = new TCanvas("c1", "c1");
  TH1* hNSlc = sNSlc.ToTH1(6.6e20);
  hNSlc->Draw("hist");
  c1->Print("nSlcs.png");

  // Let's now plot both with/without the cuts
  TCanvas* c2 = new TCanvas("c2", "c2");
  TH1* hNSlc10 = sNSlc10.ToTH1(6.6e20);
  TH1* hNNuSlc3 = sNNuSlc3.ToTH1(6.6e20);
  hNSlc->Draw("hist");
  hNSlc10->SetLineColor(kRed + 2);
  hNSlc10->Draw("hist same");
  hNNuSlc3->SetLineColor(kBlue + 2);
  hNNuSlc3->Draw("hist same");

  //Drawing a legend because we are not hobos
  TLegend* leg = new TLegend(0.6, 0.7, 0.810, 0.8);
  leg->AddEntry(hNSlc, "All Slices", "l");
  leg->AddEntry(hNSlc10, "At least 10 slices", "l");
  leg->AddEntry(hNNuSlc3, "At least 3 nu slices", "l");
  leg->Draw();
  c2->Print("trkLen.png");
}
