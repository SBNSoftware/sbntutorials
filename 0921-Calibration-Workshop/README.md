# September 2021 Workshop

This folder contains two ways to do analysis on the Calibration NTuples.
The ```macro``` sub-folder is a ROOT macro, and the ```jupyter```
sub-folder is a jupyter notebook. Clone this git repository, go into
those folders, and run the setup scripts / follow the instructions to
get started.


### Calibration NTuples

Calibration analysis is based around the "Calibration NTuples" which have been produced for ICARUS/SBND Data and MC. These are regular ROOT files which have useful information from detector reconstruction stored in ROOT TTree's. 

The TPC Calibration information is stored in two TDirectory's -- calskimE and caloskimW -- for the two ICARUS Cryostats (in SBND, just caloskim). These TDirectories each contain a TTree, "TrackCaloSkim", in which each entry is a reconstructed track with track-level, hit-level, and truth-level (for MC) information saved.

In particular, each entry in the TTree is a ```TrackInfo``` object as defined here: https://github.com/SBNSoftware/sbnobj/blob/develop/sbnobj/Common/Calibration/TrackCaloSkimmerObj.h#L180. The variable names in the nested structure at this link have comments indicating the content of each variable.

A few general comments:

The code which generates these NTuples only saves certain tracks from the reconstruction. In particular, it requires the input Track to cross the Cathode (from a techical perspective, it requires the track to have an assocaited ```anab::T0``` from Pandora -- this ```T0``` can be generalized though to any source, e.g. CRT or PMT). In addition, it requires the track to pass one the configured ```SelectionTool```'s. In both SBND and ICARUS, these files have been generated with the tools listed as (0) stopping tracks, (1) Anode+Cathode crossing tracks, (2) throughgoing tracks. The selection tool which selected each track is saved as an index (0, 1, or 2) in the ```selected``` variable. The configurations used to generate these files can be found here: https://github.com/SBNSoftware/sbncode/tree/develop/sbncode/Calibration/fcl.

Variables are stored per-plane -- so there is for example ```hits0```, ```hits1```, and ```hits2``` variables each storing a list of hit's on each track. This enumeration is counting the planes from the inside of the TPC to the outside; so they are 1st Induction, then 2nd Induction, then Collection.

The various "fit" variables have been deprecated since the original creation of this class and are no longer used / filled.

The ```WireInfo``` vector's contain raw ADC values for the wires that each track has hits on. However, these are not always filled (it depends on the type of production).
