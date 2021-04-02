// Make a plot with cuts
#include "sbnana/CAFAna/Core/Binning.h"
#include "sbnana/CAFAna/Core/Spectrum.h"
#include "sbnana/CAFAna/Core/SpectrumLoader.h"

using namespace ana;

#include "sbnana/CAFAna/StandardRecord/Proxy/SRProxy.h"

#include "TCanvas.h"
#include "TH1.h"
#include "TLegend.h"

// ---- VARS -----
// A Var returns a number per slice, a.k.a. variables to plot
const Var kLongestTrkLen([](const caf::SRSliceProxy* slc) -> double {
  double len(-5.f);
  for (auto const& trk : slc->reco.trk) {
    if (trk.len > len)
      len = trk.len;
  }
  return len;
});

// A MultiVar returns many numbers per slice, a.k.a. variables to plot
const MultiVar kAllTrkLen([](const caf::SRSliceProxy* slc) -> std::vector<double> {
  std::vector<double> len;
  for (auto const& trk : slc->reco.trk) {
    len.push_back(trk.len);
  }
  return len;
});

void MultiVars(const std::string inputName = "/pnfs/sbnd/persistent/sbndpro/mcp/mc/workshop/SBNWorkshop0421/prodoverlay_corsika_cosmics_proton_genie_nu_spill_gsimple-configf-v1_tpc/v09_19_00_01/caf/flat_caf_0-9f00feff-e742-419d-9856-9fe7428b93a9.root")
{
  // Environment variables and wildcards work as arguments to
  // SpectrumLoader. As do SAM datasets.
  // Source of events
  SpectrumLoader loader(inputName);

  // ---- SPECTRA -----
  // A spectrum is a histogram with associated POT information
  const Binning binsLen = Binning::Simple(40, 0, 200);

  // Spectrum(SpectrumName, Binning, SpectrumLoader, MultiVar, SpillCut, Cut)
  Spectrum sAllTrkLen("sAllTrkLen", binsLen, loader, kAllTrkLen, kNoSpillCut, kNoCut);
  Spectrum sLongestTrkLen("sLongestTrkLen", binsLen, loader, kLongestTrkLen, kNoSpillCut, kNoCut);

  // This is the call that actually fills in the spectrum
  loader.Go();

  // ---- DRAW -----
  // For plotting purposes we can convert spectra to a TH1
  TCanvas* c1 = new TCanvas("c1", "c1");
  TH1* hAllTrkLen = sAllTrkLen.ToTH1(6.6e20);
  TH1* hLongestTrkLen = sLongestTrkLen.ToTH1(6.6e20);
  hAllTrkLen->Draw("hist");
  hLongestTrkLen->SetLineColor(kBlue + 2);
  hLongestTrkLen->Draw("hist same");

  //Drawing a legend because we are not hobos
  TLegend* leg = new TLegend(0.6, 0.7, 0.85, 0.8);
  leg->AddEntry(hAllTrkLen, "All Tracks", "l");
  leg->AddEntry(hLongestTrkLen, "Longest Track", "l");
  leg->Draw();
  c1->Print("allTrkLen.png");
}
