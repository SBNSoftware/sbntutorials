#include "sbnanaobj/StandardRecord/Proxy/SRProxy.h"

#include "sbnana/CAFAna/Core/Var.h"
#include "sbnana/CAFAna/Core/Cut.h"

namespace ana
{
  //////////////
  // Simple Vars
  //////////////
  
  // Truth index
  const Var kTruthIndex = SIMPLEVAR(truth.index);

  // The SIMPLEVAR preprocessor macro allows us to shorthand for the following, traditional way of defining a Var:
  /*
  const Var kTruthIndex([](const caf::SRSliceProxy* slc) -> float {
      return slc->truth.index;
    });
  */

  // Primary energy
  const Var kPrimaryEnergy = SIMPLEVAR(truth.E);

  // Longest track in a slice
  const Var kLongestTrkLen([](const caf::SRSliceProxy* slc) -> float {
      float len(-5.f);
      for (auto const& trk : slc->reco.trk)
      {
	if (trk.len > len) len = trk.len;
      }
      return len;
    });

  //////////////
  // Simple Cuts
  //////////////

  // Select slices originating from a neutrino
  const Cut kIsNuSlice = ( kTruthIndex >= 0.f );

  // Select only slices that are nu mu CC in origin.
  const Cut kIsNuMuCC([](const caf::SRSliceProxy* slc) {
      return ( kIsNuSlice(slc) && slc->truth.iscc && ( slc->truth.pdg == 14 || slc->truth.pdg == -14 ) );
    });

  ////////////
  // MultiVars
  ////////////

  // All track lengths from each slice
  const MultiVar kAllTrkLen([](const caf::SRSliceProxy* slc) -> std::vector<double> {
      std::vector<double> len;
      for (auto const& trk : slc->reco.trk) len.push_back(trk.len);
      return len;
    });
  
  ////////////
  // SpillCuts
  ////////////
  
  // A simple CRT hit veto.
  const SpillCut kCRTHitVeto([](const caf::SRSpillProxy* sr){
      for (auto const& crtHit: sr->crt_hits)
      {
	auto thistime = crtHit.time - 1600.; // manually shift to bring beam spill start to zero
	if (thistime > -0.1 && thistime < 1.8 && crtHit.pe > 100)
	  return false;
      }
      return true;
    });
}
