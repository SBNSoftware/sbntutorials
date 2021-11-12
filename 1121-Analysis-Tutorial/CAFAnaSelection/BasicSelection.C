// SBNAna includes.
#include "sbnana/CAFAna/Core/SpectrumLoader.h"
#include "sbnana/CAFAna/Core/Spectrum.h"
#include "sbnana/CAFAna/Core/Binning.h"

// ROOT includes.
#include "TFile.h"
#include "TH1D.h"

// Definitions for Vars and Cuts.
#include "Definitions.h"

using namespace ana;

void BasicSelection()
{
  // Some useful variables for later.
  const std::string TargetFile = "/pnfs/icarus/persistent/users/mueller/CAFs/icarus_nucosmics.flat.root";
  const double TargetPOT(6.6e20);

  // The SpectrumLoader object handles the loading of CAFs and the creation of Spectrum.
  SpectrumLoader NuLoader(TargetFile);

  // Side note: I find it to be good practice to add a letter to each object to denote the type.
  // It helps me keep track of the many different objects and makes the code more readable (opinion).

  // Create the binning schemes for the Vars we wish to plot.
  const Binning bPrimaryEnergy = Binning::Simple(20, 0, 3.0);
  const Binning bTrackLength = Binning::Simple(40, 0, 200);

  // Create a simple Spectrum showing the primary neutrino energy of only slices with a nu mu CC interaction.
  Spectrum sNuEnergy( "Neutrino Energy [GeV]",     // A label for the Spectrum.
		      bPrimaryEnergy,              // Use 20 bins from 0.0 to 3.0 GeV
		      NuLoader,                    // Associate this Spectrum with the NuLoader object (and its target CAF)
		      kPrimaryEnergy,              // The Var to plot.
		      kNoSpillCut,                 // The SpillCut to use (none in this case).
		      kIsNuMuCC );                 // The Cut to use (only true nu mu CC slices).

  // Let's do the same as above, but add a SpillCut to see how many nu mu CC slices survive a simple CRT hit veto.
  Spectrum sNuEnergyNoCRT( "Neutrino Energy [GeV]",     // A label for the Spectrum.
			   bPrimaryEnergy,              // Use 20 bins from 0.0 to 3.0 GeV
			   NuLoader,                    // Associate this Spectrum with the NuLoader object (and its target CAF)
			   kPrimaryEnergy,              // The Var to plot.
			   kCRTHitVeto,                 // Use a simple CRT Hit SpillCut.
			   kIsNuMuCC );                 // The Cut to use (only true nu mu CC slices).

  // Create a simple Spectrum showing the length of all tracks in all slices with a nu mu CC interaction.
  Spectrum sTrackLen( "Track Length [cm]",         // A label for the Spectrum.
		      bTrackLength,                // Use 20 bins from 0.0 to 3.0 GeV
		      NuLoader,                    // Associate this Spectrum with the NuLoader object (and its target CAF)
		      kAllTrkLen,                  // The Var to plot.
		      kNoSpillCut,                 // The SpillCut to use (none in this case).
		      kIsNuMuCC );                 // The Cut to use (only true nu mu CC slices).

  // Now that each Spectrum is defined, use the Go() method to populate the Spectrum objects.
  NuLoader.Go();

  // Write the Spectrum objects to a file as a TH1 object (can also use TCanvas to make better looking plots).
  TFile FOut("Spectra.root", "recreate");
  
  TH1D* hNuEnergy;
  hNuEnergy = sNuEnergy.ToTH1(TargetPOT); // This handles the conversion to a TH1 and any POT scaling.
  hNuEnergy->Write("NuEnergy");

  TH1D* hNuEnergyNoCRT;
  hNuEnergyNoCRT = sNuEnergyNoCRT.ToTH1(TargetPOT);
  hNuEnergyNoCRT->Write("NuEnergyNoCRT");
  
  TH1D* hTrackLen;
  hTrackLen = sTrackLen.ToTH1(TargetPOT);
  hTrackLen->Write("TrackLengths");

  FOut.Close();
}
