// Compare and combining spectra
#include "sbnana/CAFAna/Core/Binning.h"
#include "sbnana/CAFAna/Core/Ratio.h"
#include "sbnana/CAFAna/Core/Spectrum.h"
#include "sbnana/CAFAna/Core/SpectrumLoader.h"

using namespace ana;

#include "sbnana/CAFAna/StandardRecord/Proxy/SRProxy.h"

#include "TCanvas.h"
#include "TH1.h"
#include "TLegend.h"

// ---- VARS -----
// A Var returns a number per slice, a.k.a. variables to plot
const Var kNTrk = SIMPLEVAR(reco.ntrk);

void MultipleSpecta(const std::string file1 = "/pnfs/sbnd/persistent/sbndpro/mcp/mc/workshop/SBNWorkshop0421/prodoverlay_corsika_cosmics_proton_genie_nu_spill_gsimple-configf-v1_tpc/v09_19_00_01/caf/flat_caf_0-9f00feff-e742-419d-9856-9fe7428b93a9.root", std::string file2 = "/pnfs/sbnd/persistent/sbndpro/mcp/mc/workshop/SBNWorkshop0421/prodoverlay_corsika_cosmics_proton_genie_nu_spill_gsimple-configf-v1_tpc/v09_19_00_01/caf/flat_caf_1-73fae8f1-1758-43b3-bb5f-ec5f0a925d9f.root")
{
  // Environment variables and wildcards work as arguments to
  // SpectrumLoader. As do SAM datasets.
  // Source of events
  SpectrumLoader loader1(file1);
  SpectrumLoader loader2(file2);

  // ---- SPECTRA -----
  // A spectrum is a histogram with associated POT information
  const Binning binsN = Binning::Simple(10, 0, 10);

  // HistAxis(Title, Binning, Var)
  const HistAxis axNTrk("Number of Trks", binsN, kNTrk);

  // Spectrum(Spectrumloader, HistAxis, Cut)
  Spectrum sNTrks1(loader1, axNTrk, kNoCut);
  Spectrum sNTrks2(loader2, axNTrk, kNoCut);

  // This is the call that actually fills in the spectrum
  loader1.Go();
  loader2.Go();

  // ---- DRAW -----
  // Let's compare the two spectras
  TCanvas* c1 = new TCanvas("c1", "c1");
  TH1* hNTrks1 = sNTrks1.ToTH1(6.6e20);
  TH1* hNTrks2 = sNTrks2.ToTH1(6.6e20);
  hNTrks1->Draw("hist");
  hNTrks2->SetLineColor(kBlue + 2);
  hNTrks2->Draw("hist same");
  TLegend* leg = new TLegend(0.6, 0.7, 0.85, 0.8);
  leg->AddEntry(hNTrks1, "File 1", "l");
  leg->AddEntry(hNTrks2, "File 2", "l");
  leg->Draw();
  c1->Print("nTrksCompare.png");

  // We can add together the specatras into a new spectrum
  Spectrum sNTrksCombined = sNTrks1 + sNTrks2;
  // ---- DRAW -----
  // For plotting purposes we can convert spectra to a TH1
  TCanvas* c2 = new TCanvas("c2", "c2");
  TH1* hNTrksCombined = sNTrksCombined.ToTH1(6.6e20);
  hNTrksCombined->Draw("hist");
  c2->Print("nTrksCombine.png");

  // We can take the ratio between the two speactras
  Ratio sNTrksRatio = sNTrks1 / sNTrks2;
  // ---- DRAW -----
  // For plotting purposes we can convert spectra to a TH1
  TCanvas* c3 = new TCanvas("c3", "c3");
  TH1* hNTrksRatio = sNTrksRatio.ToTH1();
  hNTrksRatio->Draw("hist");
  c3->Print("nTrksRatio.png");
}
