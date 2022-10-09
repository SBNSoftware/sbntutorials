#include "sbnana/CAFAna/Core/Binning.h"
#include "sbnana/CAFAna/Core/SpectrumLoader.h"
#include "sbnana/CAFAna/Core/EnsembleRatio.h"
#include "sbnana/CAFAna/Core/EnsembleSpectrum.h"
#include "sbnana/CAFAna/Core/LoadFromFile.h"
#include "sbnana/CAFAna/Core/Var.h"
#include "sbnana/CAFAna/Cuts/TruthCuts.h"
#include "sbnana/CAFAna/Systs/SBNWeightSysts.h"
#include "sbnana/CAFAna/Analysis/ExpInfo.h"
#include "sbnanaobj/StandardRecord/Proxy/SRProxy.h"

#include "sbnana/SBNAna/Vars/Vars.h"
#include "sbnana/SBNAna/Vars/Binnings.h"
#include "sbnana/SBNAna/Vars/NueVars.h"
#include "sbnana/SBNAna/Cuts/Cuts.h"
#include "sbnana/SBNAna/Cuts/TruthCuts.h"
#include "sbnana/SBNAna/Cuts/NumuCuts.h"

#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TPad.h"

using namespace ana;

// DEFINE THE VARIABLES YOU WANT

  const Var kSlcTrkDirY([](const caf::SRSliceProxy *slc) -> double
       {
         return slc->nuid.crlongtrkdiry;
       });

// GENERIC CUTS:

  const Cut kSlcFlashMatchDataCut([](const caf::SRSliceProxy *slc){
	  return (kSlcHasFlashMatch(slc) && slc->fmatch.score>0. && slc->fmatch.score<12.);
	});

//// DIRECTLY FROM Numu Cuts the values here you van updated running: setup icaruscode v09_45_00 -q e20:prof && lar -c dump_icarus_geometry.fcl && grep 'active volume box' ICARUS-geometry.txt [wirh the newest icaruscode realise]
  const Cut kRFiducial([](const caf::SRSliceProxy* slc) {
    return ( !isnan(slc->vertex.x) &&
	     ( ( slc->vertex.x < -61.94 - 25 && slc->vertex.x > -358.49 + 25 ) ||
	       ( slc->vertex.x > 61.94 + 25 && slc->vertex.x < 358.49 - 25 ) ) &&
	     !isnan(slc->vertex.y) &&
	     ( slc->vertex.y > -181.86 + 25 && slc->vertex.y < 134.96 - 25 ) &&
	     !isnan(slc->vertex.z) &&
	     ( slc->vertex.z > -894.951 + 30 && slc->vertex.z < 894.951 - 50 ) );
  });

  const Cut kFContained([](const caf::SRSliceProxy* slc) -> double {
      bool Contained;
    int PTrackCon(-1);
    for (std::size_t i(0); i < slc->reco.trk.size(); ++i)
      {
        auto const& trk = slc->reco.trk.at(i);
        Contained = ( !isnan(trk.end.x) &&
	     ( ( trk.end.x < -61.94 - 5. && trk.end.x > -358.49 + 5. ) ||
	       ( trk.end.x > 61.94 + 5. && trk.end.x < 358.49 - 5. ) ) &&
	     !isnan(trk.end.y) &&
	     ( trk.end.y > -181.86 + 5. && trk.end.y < 134.96 - 5. ) &&
	     !isnan(trk.end.z) &&
	     ( trk.end.z > -894.951 + 5. && trk.end.z < 894.951 - 5. ) );
        if ( Contained )
	  { PTrackCon = i; }
      }
    return PTrackCon;
  });

  const Cut kClearCosmic([](const caf::SRSliceProxy* slc){
  	return (slc -> is_clear_cosmic == 0);
	});

  const Cut kTrkLenCut([](const caf::SRSliceProxy* slc){
        return kLongestTrackLength(slc) > 50.0;
        });


    // Full Cuts
//  const Cut kNumuCC_Selection =  kNoCut;
  const Cut kNumuCC_Selection = kClearCosmic && kTrkLenCut;
//  const Cut kNumuCC_Selection = kClearCosmic && kRFiducial && kFContained && kTrkLenCut;



    // SpillCuts
  const SpillCut kRFiducialSpillCut([](const caf::SRSpillProxy* sr) {
      unsigned int counter(0);
        for (auto const& slc : sr->slc) {
//          if (slc.tmatch.index < 0) continue;
          if (kRFiducial(&slc)) ++counter;
        }
      return counter > 0;
  });

  const SpillCut kSlcFlashMatchDataSpillCut([](const caf::SRSpillProxy* sr) {
      unsigned int counter(0);
        for (auto const& slc : sr->slc) {
//          if (slc.tmatch.index < 0) continue;
          if (kSlcFlashMatchDataCut(&slc)) ++counter;
        }
      return counter > 0;
  });


  const SpillCut kTrkLenSpillCut([](const caf::SRSpillProxy* sr) {
      unsigned int counter(0);
        for (auto const& slc : sr->slc) {
//          if (slc.tmatch.index < 0) continue;
          if (kTrkLenCut(&slc)) ++counter;
        }
      return counter > 0;
  });


  const SpillCut krun_SpillCut([](const caf::SRSpillProxy* sr) {
      unsigned int counter(0);
        for (auto const& slc : sr->slc) {
          if (sr->hdr.run == 7924) ++counter; //7418 7924 7926
        }
      return counter > 0;
  });


  const SpillCut kNumuCC_SelectionSpillCut([](const caf::SRSpillProxy* sr) {
// /* /////comment to swich with showers
      unsigned int counter(0);
        for (auto const& slc : sr->slc) {
        for (auto const& trk : slc.reco.trk) {
          if (kNumuCC_Selection(&slc)) 
          {
            std::cout << "Event " << sr->hdr.run << " " << sr->hdr.subrun << " " << sr->hdr.evt /*<< "\n" */ 
                      << " -- vtx " << slc.vertex.x << " " << slc.vertex.y << " " << slc.vertex.z 
                      << " -- trkStart " << trk.start.x << " " << trk.start.y << " " << trk.start.z                      
                      << " -- crlongtrkdiry " << slc.nuid.crlongtrkdiry  << " -- trkLength " << trk.len
                      << " -- trkEnd " << trk.end.x << " " << trk.end.y << " " << trk.end.z 
                      << " -- fmScore " << slc.fmatch.score  << std::endl;
                      
            ++counter;
          }
        }}//}
      return counter > 0;
  });
// */ /////comment to swich with showers

/* /////comment to swich with tracks
      unsigned int counter(0);
        for (auto const& slc : sr->slc) {
        for (auto const& shw : slc.reco.shw) {
          if (kNumuCC_Selection(&slc)) {
            std::cout << "Event " << sr->hdr.run << " " << sr->hdr.subrun << " " << sr->hdr.evt
                      << " -- vtx " << slc.vertex.x << " " << slc.vertex.y << " " << slc.vertex.z 
                      << " -- swrStart " << shw.start.x << ", " << shw.start.y << ", " << shw.start.z  
                      << " -- swrEnd " << shw.end.x << ", " << shw.end.y << ", " << shw.end.z  
                      << " -- crlongtrkdiry " << slc.nuid.crlongtrkdiry  << " -- swrLength " << shw.len
                      << " -- fmScore " << slc.fmatch.score  << std::endl;
            ++counter;
          }
        }}
      return counter > 0;
  });
*/ /////comment to swich with tracks


    // Binning
  const Binning kEvtBinning       = Binning::Simple(1000000,0.f,1000000.f);
  const Binning kLengthBinning    = Binning::Simple(80,0.,400);
  const Binning kNucltdiryBinning = Binning::Simple(50,-1.,1.f);
  
    // HistAxis 
  const HistAxis axtdy   ("cltdiry",    kNucltdiryBinning,  kSlcTrkDirY);
  const HistAxis axtkl   ("trklength",  kLengthBinning,     kLongestTrackLength);



