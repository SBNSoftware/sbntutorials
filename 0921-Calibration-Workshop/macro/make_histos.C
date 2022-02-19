#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

void make_histos(bool verbose=false) {


  gStyle->SetOptStat(0);


  //  TCanvas* cnvs_az2 = new TCanvas("cnvs_az2", "c1", 1,1,800,700);   
  THStack *hs_az2 = new THStack("hs_az2","");
  //TCanvas* cnvs_z2 = new TCanvas("cnvs_z2", "c1", 1,1,800,700);
  THStack *hs_z2 = new THStack("hs_z2","");
  //TCanvas* cnvs_az1 = new TCanvas("cnvs_az1", "c1", 1,1,800,700);
  THStack *hs_az1 = new THStack("hs_az1","");
  //TCanvas* cnvs_z1 = new TCanvas("cnvs_z1", "c1", 1,1,800,700);
  THStack *hs_z1 = new THStack("hs_z1","");
  //TCanvas* cnvs_az0 = new TCanvas("cnvs_az0", "c1", 1,1,800,700);
  THStack *hs_az0 = new THStack("hs_az0","");
  //TCanvas* cnvs_z0 = new TCanvas("cnvs_z0", "c1", 1,1,800,700);
  THStack *hs_z0 = new THStack("hs_z0","");
  //TCanvas* cnvs_l = new TCanvas("cnvs_l", "c1", 1,1,800,700);
  THStack *hs_l = new THStack("hs_l","");
  //TCanvas* cnvs_t0 = new TCanvas("cnvs_t0", "c1", 1,1,800,700);
  THStack *hs_t0 = new THStack("hs_t0","");
  //TCanvas* cnvs_sx = new TCanvas("cnvs_sx", "c1", 1,1,800,700);
  THStack *hs_sx = new THStack("hs_sx","");
  //TCanvas* cnvs_ex = new TCanvas("cnvs_ex", "c1", 1,1,800,700);
  THStack *hs_ex = new THStack("hs_ex",""); 
  //TCanvas* cnvs_sy = new TCanvas("cnvs_sy", "c1", 1,1,800,700);
  THStack *hs_sy = new THStack("hs_sy","");
  //TCanvas* cnvs_ey = new TCanvas("cnvs_ey", "c1", 1,1,800,700);
  THStack *hs_ey = new THStack("hs_ey","");
  //TCanvas* cnvs_sz = new TCanvas("cnvs_sz", "c1", 1,1,800,700);
  THStack *hs_sz = new THStack("hs_sz","");
  //TCanvas* cnvs_ez = new TCanvas("cnvs_ez", "c1", 1,1,800,700);
  THStack *hs_ez = new THStack("hs_ez","");
  //TCanvas* cnvs_r0 = new TCanvas("cnvs_r0", "c1", 1,1,800,700);
  THStack *hs_r0 = new THStack("hs_r0","");
  //TCanvas* cnvs_r1 = new TCanvas("cnvs_r1", "c1", 1,1,800,700);
  THStack *hs_r1 = new THStack("hs_r1","");
  //TCanvas* cnvs_r2 = new TCanvas("cnvs_r2", "c1", 1,1,800,700);
  THStack *hs_r2 = new THStack("hs_r2","");
  //TCanvas* cnvs_q0 = new TCanvas("cnvs_q0", "c1", 1,1,800,700);
  THStack *hs_q0 = new THStack("hs_q0","");
  //TCanvas* cnvs_q1 = new TCanvas("cnvs_q1", "c1", 1,1,800,700);
  THStack *hs_q1 = new THStack("hs_q1","");
  //TCanvas* cnvs_q2 = new TCanvas("cnvs_q2", "c1", 1,1,800,700);
  THStack *hs_q2 = new THStack("hs_q2","");



  cout<<"TStack"<<endl;

  // Create a histograms for the values we read.
  TH1F *h_azangle2_mc   = new TH1F("h_azangle2_mc","Relative Frequency vs  Azimuthal Angle: East Cryostat", 100., 0., 1.6);
  TH1F *h_azangle2_data = new TH1F("h_azangle2_data","Relative Frequency vs Azimuthal Angle: East Cryostat", 100., 0., 1.6);
  h_azangle2_mc->GetXaxis()->SetTitle(" Azimuthal Angle in radians ");
  h_azangle2_mc->GetYaxis()->SetTitle("Relative Frequency");
 
  TH1F *h_zangle2_mc   = new TH1F("h_zangle2_mc","Relative Frequency vs  Zenith Angle: East Cryostat", 100., 0., 1.6);
  TH1F *h_zangle2_data = new TH1F("h_zangle2_data","Relative Frequency vs Zenith Angle: East Cryostat", 100., 0., 1.6);
  h_zangle2_mc->GetXaxis()->SetTitle(" Zenith Angle in radians ");
  h_zangle2_mc->GetYaxis()->SetTitle("Relative Frequency");
 

  TH1F *h_azangle1_mc   = new TH1F("h_azangle1_mc","Relative Frequency vs  Azimuthal Angle: East Cryostat", 100., 0., 1.6);
  TH1F *h_azangle1_data = new TH1F("h_azangle1_data","Relative Frequency vs Azimuthal Angle: East Cryostat", 100., 0., 1.6);
  h_azangle1_mc->GetXaxis()->SetTitle(" Azimuthal Angle in radians ");
  h_azangle1_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_zangle1_mc   = new TH1F("h_zangle1_mc","Relative Frequency vs  Zenith Angle: East Cryostat", 100., 0., 1.6);
  TH1F *h_zangle1_data = new TH1F("h_zangle1_data","Relative Frequency vs Zenith Angle: East Cryostat", 100., 0., 1.6);
  h_zangle1_mc->GetXaxis()->SetTitle(" Zenith Angle in radians ");
  h_zangle1_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_azangle0_mc   = new TH1F("h_azangle0_mc","Relative Frequency vs  Azimuthal Angle: East Cryostat", 100., 0., 1.6);
  TH1F *h_azangle0_data = new TH1F("h_azangle0_data","Relative Frequency vs Azimuthal Angle: East Cryostat", 100., 0., 1.6);
  h_azangle0_mc->GetXaxis()->SetTitle(" Azimuthal Angle in radians ");
  h_azangle0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_zangle0_mc   = new TH1F("h_zangle0_mc","Relative Frequency vs  Zenith Angle: East Cryostat", 100., 0., 1.6);
  TH1F *h_zangle0_data = new TH1F("h_zangle0_data","Relative Frequency vs Zenith Angle: East Cryostat", 100., 0., 1.6);
  h_zangle0_mc->GetXaxis()->SetTitle(" Zenith Angle in radians ");
  h_zangle0_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_l_mc   = new TH1F("h_l_mc","Relative Frequency vs  Length: East Cryostat", 100., 0., 100.);
  TH1F *h_l_data = new TH1F("h_l_data","Relative Frequency vs Length: East Cryostat", 100., 0., 100.);
  h_l_mc->GetXaxis()->SetTitle("Muon Length in cm ");
  h_l_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_t0_mc   = new TH1F("h_t0_mc","Relative Frequency vs  T0: East Cryostat", 100., -100000., 100000.);
  TH1F *h_t0_data = new TH1F("h_t0_data","Relative Frequency vs T0: East Cryostat", 100., -100000., 100000.);
  h_t0_mc->GetXaxis()->SetTitle(" T0 in us ");
  h_t0_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_sx_mc   = new TH1F("h_sx_mc","Relative Frequency vs  Start (X): East Cryostat", 100., -100., 100.);//-100000., 100000.);
  TH1F *h_sx_data = new TH1F("h_sx_data","Relative Frequency vs Start (X): East Cryostat", 100., -100., 100.);//100., -100000., 100000.);
  h_sx_mc->GetXaxis()->SetTitle("Start (X) in cm ");
  h_sx_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_ex_mc   = new TH1F("h_ex_mc","Relative Frequency vs  End (X): East Cryostat", 100.,  -100., 100.);//-100000., 100000.);
  TH1F *h_ex_data = new TH1F("h_ex_data","Relative Frequency vs End (X): East Cryostat",  100., -100., 100.);//-100000., 100000.);
  h_ex_mc->GetXaxis()->SetTitle(" End (X) in cm ");
  h_ex_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_sy_mc   = new TH1F("h_sy_mc","Relative Frequency vs  Start (Y): East Cryostat", 100.,  -100., 100.);//-100000., 100000.);
  TH1F *h_sy_data = new TH1F("h_sy_data","Relative Frequency vs Start (Y): East Cryostat",  100., -100., 100.);//-100000., 100000.);
  h_sy_mc->GetXaxis()->SetTitle("Start (Y) in cm ");
  h_sy_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_ey_mc   = new TH1F("h_ey_mc","Relative Frequency vs  End (Y): East Cryostat", 100.,  -100., 100.);//-100000., 100000.);
  TH1F *h_ey_data = new TH1F("h_ey_data","Relative Frequency vs End (Y): East Cryostat",  100., -100., 100.);//-100000., 100000.);
  h_ey_mc->GetXaxis()->SetTitle(" End (Y) in cm ");
  h_ey_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_sz_mc   = new TH1F("h_sz_mc","Relative Frequency vs  Start (Z): East Cryostat", 100., -100., 100.);//-100000., 100000.);
  TH1F *h_sz_data = new TH1F("h_sz_data","Relative Frequency vs Start (Z): East Cryostat",  100., -100., 100.);//-100000., 100000.);
  h_sz_mc->GetXaxis()->SetTitle("Start (Z) in cm ");
  h_sz_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_ez_mc   = new TH1F("h_ez_mc","Relative Frequency vs  End (Z): East Cryostat", 100.,  -100., 100.);//-100000., 100000.);
  TH1F *h_ez_data = new TH1F("h_ez_data","Relative Frequency vs End (Z): East Cryostat",  100., -100., 100.);//-100000., 100000.);
  h_ez_mc->GetXaxis()->SetTitle(" End (Z) in cm ");
  h_ez_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_q0_mc   = new TH1F("h_q0_mc","Relative Frequency vs  dQ/dx: East Cryostat", 100., 0., 2000.);
  TH1F *h_q0_data = new TH1F("h_q0_data","Relative Frequency vs dQ/dx: East Cryostat", 100., 0., 2000.);
  h_q0_mc->GetXaxis()->SetTitle(" dQ/dx ");
  h_q0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_q1_mc   = new TH1F("h_q1_mc","Relative Frequency vs  dQ/dx: East Cryostat", 100., 0., 2000.);//-100000., 100000.);
  TH1F *h_q1_data = new TH1F("h_q1_data","Relative Frequency vs dQ/dx: East Cryostat", 100., 0., 2000.);//-100000., 100000.);
  h_q1_mc->GetXaxis()->SetTitle(" dQ/dx ");
  h_q1_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_q2_mc   = new TH1F("h_q2_mc","Relative Frequency vs  dQ/dx: East Cryostat", 100., 0., 2000.);//-100000., 100000.);
  TH1F *h_q2_data = new TH1F("h_q2_data","Relative Frequency vs dQ/dx: East Cryostat", 100., 0., 2000.);//-100000., 100000.);
  h_q2_mc->GetXaxis()->SetTitle(" dQ/dx ");
  h_q2_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_r0_mc   = new TH1F("h_r0_mc","Relative Frequency vs  Residual Range: East Cryostat", 100., 0., 150.);//-100000., 100000.);
  TH1F *h_r0_data = new TH1F("h_r0_data","Relative Frequency vs Residual Range: East Cryostat", 100., 0., 150.);// -100000., 100000.);
  h_r0_mc->GetXaxis()->SetTitle(" Residual Range in cm ");
  h_r0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_r1_mc   = new TH1F("h_r1_mc","Relative Frequency vs  Residual Range: East Cryostat", 100., 0., 150.);//100-100000., 100000.);
  TH1F *h_r1_data = new TH1F("h_r1_data","Relative Frequency vs Residual Range: East Cryostat", 100., 0., 150.);//-100000., 100000.);
  h_r1_mc->GetXaxis()->SetTitle(" Residual Range in cm ");
  h_r1_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_r2_mc   = new TH1F("h_r2_mc","Relative Frequency vs  Residual Range: East Cryostat", 100., 0., 150.);//-100000., 100000.);
  TH1F *h_r2_data = new TH1F("h_r2_data","Relative Frequency vs Residual Range: East Cryostat", 100., 0., 150.);//-100000., 100000.);
  h_r2_mc->GetXaxis()->SetTitle(" Residual Range in cm ");
  h_r2_mc->GetYaxis()->SetTitle("Relative Frequency");

  cout<<"histos"<<endl;
  //create other histograms here!


   //Get the files from ICARUS gpvm
  TFileCollection *my_files = new TFileCollection("my_files","My File List");
  my_files->Add("/pnfs/icarus/persistent/calibration/calib_ntuples/mc/ICARUS_NuMI_Nu_Cosmics/hist_prodcorsika_genie_protononly_icarus_numi_volDetEnclosure_tpc_gen_filter_g4_detsim_48288511*.root");//24037195*.root");   ///icarus/data/users/obitter/CalibrationWS21/hist_prodcorsika_genie_protononly_icarus_numi*.root");//_volDetEnclosure_tpc_gen_filter_g4_detsim_48288511_9_reco1_20210912T103409_reco2.root");//hist_prodcorsika_genie_protononly_icarus_numi*.root");//    
  ///pnfs/icarus/persistent/calibration/calib_ntuples/mc/ICARUS_NuMI_Nu_Cosmics/hist*.root"); 
  //  /icarus/data/users/obitter/CalibrationWS21/hist_prodcorsika_genie_protononly_icarus_numi*.root");//
///pnfs/icarus/persistent/calibration/calib_ntuples/mc/ICARUS_NuMI_Nu_Cosmics/
//hist_prodcorsika_genie_protononly_icarus_numi*.root");//hist_prodcorsika_genie_protononly_icarus_numi_volDetEnclosure_tpc_gen_filter_g4_detsim_48288511_9_reco1_20210912T103409_reco2.root");//hist*.root");
  std::cout << "Number of files in our MC list is " << my_files->GetNFiles() << std::endl;
  TChain myfile("caloskimE/TrackCaloSkim");
  myfile.AddFileInfoList(my_files->GetList());

  TFileCollection *my_files2 = new TFileCollection("my_files2","My File List2");
  my_files2->Add("/pnfs/icarus/persistent/calibration/calib_ntuples/data/hist_data_dl4_fstrmNUMI*.root");//hist*.root"); ///icarus/data/users/obitter/CalibrationWS21/hist_data*NUMI*.root");//_dl4_fstrmNUMI_run6106_50_20210627T040512_20210812T023813_stage0_20210812T121941_stage1-008e44f5-2b5f-49f3-9bf3-927a0c4bd7c1.root");

//his*NUMI*.root");//
//pnfs/icarus/persistent/calibration/calib_ntuples/data/hist_data_dl4_fstrmNUMI*.root"); 
  ///icarus/data/users/obitter/CalibrationWS21/hist_data_dl4_fstrmNUMI*.root");///pnfs/icarus/persistent/calibration/calib_ntuples/data/hist_data_dl4_fstrmNUMI_run6106_50_20210627T040512_20210812T023813_stage0_20210812T121941_stage1-008e44f5-2b5f-49f3-9bf3-927a0c4bd7c1.root");//hist_data_dl4_fstrmNUMI*.root");
  std::cout << "Number of files in our data list is " << my_files2->GetNFiles() << std::endl;
  TChain myfile2("caloskimE/TrackCaloSkim");
  myfile2.AddFileInfoList(my_files2->GetList());

  cout<<"files read"<<endl;

  //delcare variables
  TTreeReader myReader(&myfile);
  TTreeReader myReader2(&myfile2);
  
  TTreeReaderValue<int> selected(myReader, "trk.selected");
  TTreeReaderValue<int> selected2(myReader2, "trk.selected");
  
  TTreeReaderValue<float> startX(myReader, "trk.start.x");
  TTreeReaderValue<float> startX2(myReader2, "trk.start.x");
  
  TTreeReaderValue<float> startY(myReader, "trk.start.y");
  TTreeReaderValue<float> startY2(myReader2, "trk.start.y");

  TTreeReaderValue<float> startZ(myReader, "trk.start.z");
  TTreeReaderValue<float> startZ2(myReader2, "trk.start.z");


  TTreeReaderValue<float> endX(myReader, "trk.end.x");
  TTreeReaderValue<float> endX2(myReader2, "trk.end.x");

  TTreeReaderValue<float> endY(myReader, "trk.end.y");
  TTreeReaderValue<float> endY2(myReader2, "trk.end.y");

  TTreeReaderValue<float> endZ(myReader, "trk.end.z");
  TTreeReaderValue<float> endZ2(myReader2, "trk.end.z");

  
  TTreeReaderArray<float> dqdx_i1(myReader, "trk.hits0.dqdx");
  TTreeReaderArray<float> dqdx2_i1(myReader2, "trk.hits0.dqdx");
  
  TTreeReaderArray<float> dqdx_c(myReader, "trk.hits2.dqdx");                                                                       
  TTreeReaderArray<float> dqdx2_c(myReader2, "trk.hits2.dqdx");                                                                                                                                                                             

  TTreeReaderArray<float> dqdx_i2(myReader, "trk.hits1.dqdx");
  TTreeReaderArray<float> dqdx2_i2(myReader2, "trk.hits1.dqdx");


  TTreeReaderArray<float> rr_c(myReader, "trk.hits2.rr");
  TTreeReaderArray<float> rr2_c(myReader2, "trk.hits2.rr");

  TTreeReaderArray<float> rr_i2(myReader, "trk.hits1.rr");
  TTreeReaderArray<float> rr2_i2(myReader2, "trk.hits1.rr");

  TTreeReaderArray<float> rr_i1(myReader, "trk.hits0.rr");
  TTreeReaderArray<float> rr2_i1(myReader2, "trk.hits0.rr");

  
  TTreeReaderArray<float> z_i1(myReader, "trk.hits0.dir.z");
  TTreeReaderArray<float> z2_i1(myReader2, "trk.hits0.dir.z");
  
  TTreeReaderArray<float> y_i1(myReader, "trk.hits0.dir.y");
  TTreeReaderArray<float> y2_i1(myReader2, "trk.hits0.dir.y");
  
  TTreeReaderArray<float> x_i1(myReader, "trk.hits0.dir.x");
  TTreeReaderArray<float> x2_i1(myReader2, "trk.hits0.dir.x");
  
  TTreeReaderArray<float> z_i2(myReader, "trk.hits1.dir.z");
  TTreeReaderArray<float> z2_i2(myReader2, "trk.hits1.dir.z");
  
  TTreeReaderArray<float> y_i2(myReader, "trk.hits1.dir.y");
  TTreeReaderArray<float> y2_i2(myReader2, "trk.hits1.dir.y");
  
  TTreeReaderArray<float> x_i2(myReader, "trk.hits1.dir.x");
  TTreeReaderArray<float> x2_i2(myReader2, "trk.hits1.dir.x");
  
  TTreeReaderArray<float> z_c(myReader, "trk.hits2.dir.z");
  TTreeReaderArray<float> z2_c(myReader2, "trk.hits2.dir.z");
  
  TTreeReaderArray<float> y_c(myReader, "trk.hits2.dir.y");
  TTreeReaderArray<float> y2_c(myReader2, "trk.hits2.dir.y");
 
  TTreeReaderArray<float> x_c(myReader, "trk.hits2.dir.x");
  TTreeReaderArray<float> x2_c(myReader2, "trk.hits2.dir.x");
 
  TTreeReaderArray<bool> ontraj_c(myReader, "trk.hits2.ontraj");
  TTreeReaderArray<bool> ontraj2_c(myReader2, "trk.hits2.ontraj");

  TTreeReaderArray<bool> ontraj_i2(myReader, "trk.hits1.ontraj");
  TTreeReaderArray<bool> ontraj2_i2(myReader2, "trk.hits1.ontraj");

  TTreeReaderArray<bool> ontraj_i1(myReader, "trk.hits0.ontraj");
  TTreeReaderArray<bool> ontraj2_i1(myReader2, "trk.hits0.ontraj");

  TTreeReaderValue<float> length(myReader, "trk.length");
  TTreeReaderValue<float> length2(myReader2, "trk.length");

  TTreeReaderValue<float> t0(myReader, "trk.t0");
  TTreeReaderValue<float> t02(myReader2, "trk.t0");

  TTreeReaderArray<float> integral_c(myReader, "trk.hits2.h.integral");
  TTreeReaderArray<float> integral2_c(myReader2, "trk.hits2.h.integral");

  TTreeReaderArray<float> integral_i2(myReader, "trk.hits1.h.integral");
  TTreeReaderArray<float> integral2_i2(myReader2, "trk.hits1.h.integral");

  TTreeReaderArray<float> integral_i1(myReader, "trk.hits0.h.integral");
  TTreeReaderArray<float> integral2_i1(myReader2, "trk.hits0.h.integral");

  TTreeReaderArray<float> width_c(myReader, "trk.hits2.h.width");
  TTreeReaderArray<float> width2_c(myReader2, "trk.hits2.h.width");

  TTreeReaderArray<float> width_i2(myReader, "trk.hits1.h.width");
  TTreeReaderArray<float> width2_i2(myReader2, "trk.hits1.h.width");

  TTreeReaderArray<float> width_i1(myReader, "trk.hits0.h.width");
  TTreeReaderArray<float> width2_i1(myReader2, "trk.hits0.h.width");

  TTreeReaderArray<uint16_t> tpc_c(myReader, "trk.hits2.h.tpc");
  TTreeReaderArray<uint16_t> tpc2_c(myReader2, "trk.hits2.h.tpc");

  TTreeReaderArray<uint16_t> tpc_i2(myReader, "trk.hits1.h.tpc");
  TTreeReaderArray<uint16_t> tpc2_i2(myReader2, "trk.hits1.h.tpc");

  TTreeReaderArray<uint16_t> tpc_i1(myReader, "trk.hits0.h.tpc");
  TTreeReaderArray<uint16_t> tpc2_i1(myReader2, "trk.hits0.h.tpc");

  TTreeReaderArray<uint16_t> wire_c(myReader, "trk.hits2.h.wire");
  TTreeReaderArray<uint16_t> wire2_c(myReader2, "trk.hits2.h.wire");

  TTreeReaderArray<uint16_t> wire_i2(myReader, "trk.hits1.h.wire");
  TTreeReaderArray<uint16_t> wire2_i2(myReader2, "trk.hits1.h.wire");

  TTreeReaderArray<uint16_t> wire_i1(myReader, "trk.hits0.h.wire");
  TTreeReaderArray<uint16_t> wire2_i1(myReader2, "trk.hits0.h.wire");

  TTreeReaderArray<float> time_c(myReader, "trk.hits2.h.time");
  TTreeReaderArray<float> time2_c(myReader2, "trk.hits2.h.time");

  TTreeReaderArray<float> time_i2(myReader, "trk.hits1.h.time");
  TTreeReaderArray<float> time2_i2(myReader2, "trk.hits1.h.time");

  TTreeReaderArray<float> time_i1(myReader, "trk.hits0.h.time");
  TTreeReaderArray<float> time2_i1(myReader2, "trk.hits0.h.time");

  TTreeReaderArray<float> pitch_c(myReader, "trk.hits2.pitch");
  TTreeReaderArray<float> pitch2_c(myReader2, "trk.hits2.pitch");

  TTreeReaderArray<float> pitch_i2(myReader, "trk.hits1.pitch");
  TTreeReaderArray<float> pitch2_i2(myReader2, "trk.hits1.pitch");

  TTreeReaderArray<float> pitch_i1(myReader, "trk.hits0.pitch");
  TTreeReaderArray<float> pitch2_i1(myReader2, "trk.hits0.pitch");


   double num = 0.0;
   double num2 = 0.0;
   int a = 0;
   int j = 0;
   int k = 0;
   double angle[52000];
   double angle2[52000];
   double zangle[52000];
   double zangle2[52000];
   cout<<"vars declared"<<endl;



   //MC Azimuthal Angle
   while (myReader.Next()) {
     a++;
     cout<<"file "<<a<<endl;
     if(*selected != 0) continue; //if not stopping, move one.

     //only here if stopping
 
     //can add other track-level variables here

     h_l_mc->Fill(*length);
     h_t0_mc->Fill(*t0);    
     h_sx_mc->Fill(*startX);
     h_sy_mc->Fill(*startY);
     h_sz_mc->Fill(*startZ);
     h_ex_mc->Fill(*endX);
     h_ey_mc->Fill(*endY);
     h_ez_mc->Fill(*endZ);
     cout<<"track-level done"<<endl;
     //get the last traj point on the collection plane
     int last_i = y_c.GetSize()-1;
     int last_j = y_i2.GetSize()-1;
     int last_k = y_i1.GetSize()-1;
     
     //if not on thr trajectory, continue
     if(ontraj_c[last_i]!=1) continue;

     h_azangle2_mc->Fill( TMath::ATan(x_c[last_i]/z_c[last_i]) );
     h_zangle2_mc->Fill( TMath::ATan(abs( (sqrt(x_c[last_i]*x_c[last_i] + y_c[last_i]*y_c[last_i]))) / (z_c[last_i]) ) );
     h_q2_mc->Fill(dqdx_c[last_i]);
     h_r2_mc->Fill(rr_c[last_i]);
     cout<<"collection done"<<endl;

     //     if(verbose) 
     // cout << "MC angle " << TMath::ATan(x_c[last_i]/z_c[last_i]) << endl;

     //and fill all the other histograms related to traj points too
     

     if(ontraj_i2[last_j]!=1) continue;

     h_azangle1_mc->Fill( TMath::ATan(x_i2[last_j]/z_i2[last_j]) );
     h_zangle1_mc->Fill( TMath::ATan(abs( (sqrt(x_i2[last_j]*x_i2[last_j] + y_i2[last_j]*y_i2[last_j]))) / (z_i2[last_j]) ) );
     h_q1_mc->Fill(dqdx_i2[last_j]);
     h_r1_mc->Fill(rr_i2[last_j]);

     cout<<"induction 2 done"<<endl;
     if(ontraj_i1[last_k]!=1) continue;

     h_azangle0_mc->Fill( TMath::ATan(x_i1[last_k]/z_i1[last_k]) );
     h_zangle0_mc->Fill( TMath::ATan(abs( (sqrt(x_i1[last_k]*x_i1[last_k] + y_i1[last_k]*y_i1[last_k]))) / (z_i1[last_k]) ) );
     h_q0_mc->Fill(dqdx_i1[last_k]);
     h_r0_mc->Fill(rr_i1[last_k]);

     cout<<"induction 1 done"<<endl;
   }//end while myReader

   cout<<"MC done"<<endl;

   //Data Azimuthal Angle
   while (myReader2.Next()) {
     if(*selected2 != 0) continue; //if not stopping, move one.

     //only here if stopping
     
     h_l_data->Fill(*length2);
     h_t0_data->Fill(*t02);
     h_sx_data->Fill(*startX2);
     h_sy_data->Fill(*startY2);
     h_sz_data->Fill(*startZ2);
     h_ex_data->Fill(*endX2);
     h_ey_data->Fill(*endY2);
     h_ez_data->Fill(*endZ2);

     //get the last traj point on the collection plane
     int last_i2 = y2_c.GetSize()-1;
     int last_j2 = y2_i2.GetSize()-1;
     int last_k2 = y2_i1.GetSize()-1;
     //if not on thr trajectory, continue
     if(ontraj2_c[last_i2]!=1) continue;

     h_azangle2_data->Fill( TMath::ATan(x2_c[last_i2]/z2_c[last_i2]) );
     h_zangle2_data->Fill( TMath::ATan(abs( (sqrt(x2_c[last_i2]*x2_c[last_i2] + y2_c[last_i2]*y2_c[last_i2]))) / (z2_c[last_i2]) ) );
     h_q2_data->Fill(dqdx2_c[last_i2]);
     h_r2_data->Fill(rr2_c[last_i2]);


     //if(verbose) 
     //cout << "MC angle " << TMath::ATan(x_c[last_i]/z_c[last_i]) << endl;

     //and fill all the other histograms related to traj points too
     

     if(ontraj2_i2[last_j2]!=1) continue;

     h_azangle1_data->Fill( TMath::ATan(x2_i2[last_j2]/z2_i2[last_j2]) );
     h_zangle1_data->Fill( TMath::ATan(abs( (sqrt(x2_i2[last_j2]*x2_i2[last_j2] + y2_i2[last_j2]*y2_i2[last_j2]))) / (z2_i2[last_j2]) ) );
     h_q1_data->Fill(dqdx2_i2[last_j2]);
     h_r1_data->Fill(rr2_i2[last_j2]);


     if(ontraj2_i1[last_k2]!=1) continue;

     h_azangle0_data->Fill( TMath::ATan(x2_i1[last_k2]/z2_i1[last_k2]) );
     h_zangle0_data->Fill( TMath::ATan(abs( (sqrt(x2_i1[last_k2]*x2_i1[last_k2] + y2_i1[last_k2]*y2_i1[last_k2]))) / (z2_i1[last_k2]) ) );
     h_q0_data->Fill(dqdx2_i1[last_k2]);
     h_r0_data->Fill(rr2_i1[last_k2]);





   }//end while myReader2
   
   //TFile myOutput_file("histogram_output.root","RECREATE");
   //myOutput_file.Write(h_azangle2_mc);
   //myOutput_file.Write(h_azangle2_data);
   //myOutput_file.Close();

   cout<<"data done"<<endl;

   

   //normalizing MC distribution
   TH1*h1 = (TH1*)(h_azangle2_mc->Clone("h1"));
   h1->Scale(1./h1->Integral());
   TH1*h1a = (TH1*)(h_azangle1_mc->Clone("h1a"));
   h1a->Scale(1./h1a->Integral());
   TH1*h1b = (TH1*)(h_azangle0_mc->Clone("h1b"));
   h1b->Scale(1./h1b->Integral());
   TH1*h1c = (TH1*)(h_zangle2_mc->Clone("h1c"));
   h1c->Scale(1./h1c->Integral());
   TH1*h1d = (TH1*)(h_zangle1_mc->Clone("h1d"));
   h1d->Scale(1./h1d->Integral());
   TH1*h1e = (TH1*)(h_zangle0_mc->Clone("h1e"));
   h1e->Scale(1./h1e->Integral());
   TH1*h1f = (TH1*)(h_q2_mc->Clone("h1f"));
   h1f->Scale(1./h1f->Integral());
   TH1*h1g = (TH1*)(h_q1_mc->Clone("h1g"));
   h1g->Scale(1./h1g->Integral());
   TH1*h1h = (TH1*)(h_q0_mc->Clone("h1h"));
   h1h->Scale(1./h1h->Integral());
   TH1*h1i = (TH1*)(h_r2_mc->Clone("h1i"));
   h1i->Scale(1./h1i->Integral());
   TH1*h1j = (TH1*)(h_r1_mc->Clone("h1j"));
   h1j->Scale(1./h1j->Integral());
   TH1*h1k = (TH1*)(h_r0_mc->Clone("h1k"));
   h1k->Scale(1./h1k->Integral());
   TH1*h1l = (TH1*)(h_l_mc->Clone("h1l"));
   h1l->Scale(1./h1l->Integral());
   TH1*h1m = (TH1*)(h_t0_mc->Clone("h1m"));
   h1m->Scale(1./h1m->Integral());
   TH1*h1n = (TH1*)(h_sx_mc->Clone("h1n"));
   h1n->Scale(1./h1n->Integral());
   TH1*h1o = (TH1*)(h_sy_mc->Clone("h1o"));
   h1o->Scale(1./h1o->Integral());
   TH1*h1p = (TH1*)(h_sz_mc->Clone("h1p"));
   h1p->Scale(1./h1p->Integral());
   TH1*h1q = (TH1*)(h_ex_mc->Clone("h1q"));
   h1q->Scale(1./h1q->Integral());
   TH1*h1r = (TH1*)(h_ey_mc->Clone("h1r"));
   h1r->Scale(1./h1r->Integral());
   TH1*h1s = (TH1*)(h_ez_mc->Clone("h1s"));
   h1s->Scale(1./h1s->Integral());

   //normalizing data distribution
   //   TH1*h2 = (TH1*)(h_azangle2_data->Clone("h2"));
   //h2->Scale(1./h2->Integral());
   TH1*h2 = (TH1*)(h_azangle2_data->Clone("h2"));
   h2->Scale(1./h2->Integral());
   TH1*h2a = (TH1*)(h_azangle1_data->Clone("h2a"));
   h2a->Scale(1./h2a->Integral());
   TH1*h2b = (TH1*)(h_azangle0_data->Clone("h2b"));
   h2b->Scale(1./h2b->Integral());
   TH1*h2c = (TH1*)(h_zangle2_data->Clone("h2c"));
   h2c->Scale(1./h2c->Integral());
   TH1*h2d = (TH1*)(h_zangle1_data->Clone("h2d"));
   h2d->Scale(1./h2d->Integral());
   TH1*h2e = (TH1*)(h_zangle0_data->Clone("h2e"));
   h2e->Scale(1./h2e->Integral());
   TH1*h2f = (TH1*)(h_q2_data->Clone("h2f"));
   h2f->Scale(1./h2f->Integral());
   TH1*h2g = (TH1*)(h_q1_data->Clone("h2g"));
   h2g->Scale(1./h2g->Integral());
   TH1*h2h = (TH1*)(h_q0_data->Clone("h2h"));
   h2h->Scale(1./h2h->Integral());
   TH1*h2i = (TH1*)(h_r2_data->Clone("h2i"));
   h2i->Scale(1./h2i->Integral());
   TH1*h2j = (TH1*)(h_r1_data->Clone("h2j"));
   h2j->Scale(1./h2j->Integral());
   TH1*h2k = (TH1*)(h_r0_data->Clone("h2k"));
   h2k->Scale(1./h2k->Integral());
   TH1*h2l = (TH1*)(h_l_data->Clone("h2l"));
   h2l->Scale(1./h2l->Integral());
   TH1*h2m = (TH1*)(h_t0_data->Clone("h2m"));
   h2m->Scale(1./h2m->Integral());
   TH1*h2n = (TH1*)(h_sx_data->Clone("h2n"));
   h2n->Scale(1./h2n->Integral());
   TH1*h2o = (TH1*)(h_sy_data->Clone("h2o"));
   h2o->Scale(1./h2o->Integral());
   TH1*h2p = (TH1*)(h_sz_data->Clone("h2p"));
   h2p->Scale(1./h2p->Integral());
   TH1*h2q = (TH1*)(h_ex_data->Clone("h2q"));
   h2q->Scale(1./h2q->Integral());
   TH1*h2r = (TH1*)(h_ey_data->Clone("h2r"));
   h2r->Scale(1./h2r->Integral());
   TH1*h2s = (TH1*)(h_ez_data->Clone("h2s"));
   h2s->Scale(1./h2s->Integral());



   cout<<"norm"<<endl;
   //drawing distribtions
   TCanvas* cnvs_az2 = new TCanvas("cnvs_az2", "c1", 1,1,800,700);

   h1->SetLineColor(kRed);
   h2->SetLineColor(kBlue);
   hs_az2->Add(h1);
   hs_az2->Add(h2);
   hs_az2->Draw("nostackHIST");


   hs_az2->GetXaxis()->SetTitle(" Azimuthal Angle in radians ");
   hs_az2->GetYaxis()->SetTitle("Relative Frequency");
   TText T; T.SetTextFont(42); T.SetTextAlign(21);
   T.DrawTextNDC(.5,.95,"Relative Frequency vs Azimuthal Angle (col): East Cryostat");
   auto legend = new TLegend(0.1,0.8,0.2,0.9);
   legend->AddEntry(h1,"MC");
   legend->AddEntry(h2,"Data");
   legend->Draw();
   cnvs_az2->Update();


   TCanvas* cnvs_az1 = new TCanvas("cnvs_az1", "c1", 1,1,800,700);
   h1a->SetLineColor(kRed);
   h2a->SetLineColor(kBlue);
   hs_az1->Add(h1a);
   hs_az1->Add(h2a);
   hs_az1->Draw("nostackHIST");

   hs_az1->GetXaxis()->SetTitle(" Azimuthal Angle in radians ");
   hs_az1->GetYaxis()->SetTitle("Relative Frequency");
   TText Ta; Ta.SetTextFont(42); Ta.SetTextAlign(21);
   Ta.DrawTextNDC(.5,.95,"Relative Frequency vs Azimuthal Angle (in1): East Cryostat");
   auto legenda = new TLegend(0.1,0.8,0.2,0.9);
   legenda->AddEntry(h1a,"MC");
   legenda->AddEntry(h2a,"Data");
   legenda->Draw();
   cnvs_az1->Update();

   TCanvas* cnvs_az0 = new TCanvas("cnvs_az0", "c1", 1,1,800,700);
   h1b->SetLineColor(kRed);
   h2b->SetLineColor(kBlue);
   hs_az0->Add(h1b);
   hs_az0->Add(h2b);
   hs_az0->Draw("nostackHIST");

   hs_az0->GetXaxis()->SetTitle(" Azimuthal Angle in radians ");
   hs_az0->GetYaxis()->SetTitle("Relative Frequency");
   TText Tb; Tb.SetTextFont(42); Tb.SetTextAlign(21);
   Tb.DrawTextNDC(.5,.95,"Relative Frequency vs Azimuthal Angle (in2): East Cryostat");
   auto legendb = new TLegend(0.1,0.8,0.2,0.9);
   legendb->AddEntry(h1b,"MC");
   legendb->AddEntry(h2b,"Data");
   legendb->Draw();
   cnvs_az0->Update();


   TCanvas* cnvs_z2 = new TCanvas("cnvs_z2", "c1", 1,1,800,700);
   h1c->SetLineColor(kRed);
   h2c->SetLineColor(kBlue);
   hs_z2->Add(h1c);
   hs_z2->Add(h2c);
   hs_z2->Draw("nostackHIST");


   hs_z2->GetXaxis()->SetTitle(" Zenith Angle in radians ");
   hs_z2->GetYaxis()->SetTitle("Relative Frequency");
   TText Tc; Tc.SetTextFont(42); Tc.SetTextAlign(21);
   Tc.DrawTextNDC(.5,.95,"Relative Frequency vs Zenith Angle (col): East Cryostat");
   auto legendc = new TLegend(0.1,0.8,0.2,0.9);
   legendc->AddEntry(h1c,"MC");
   legendc->AddEntry(h2c,"Data");
   legendc->Draw();
   cnvs_z2->Update();

   TCanvas* cnvs_z1 = new TCanvas("cnvs_z1", "c1", 1,1,800,700);
   h1d->SetLineColor(kRed);
   h2d->SetLineColor(kBlue);
   hs_z1->Add(h1d);
   hs_z1->Add(h2d);
   hs_z1->Draw("nostackHIST");


   hs_z1->GetXaxis()->SetTitle(" Zenith Angle in radians ");
   hs_z1->GetYaxis()->SetTitle("Relative Frequency");
   TText Td; Td.SetTextFont(42); Td.SetTextAlign(21);
   Td.DrawTextNDC(.5,.95,"Relative Frequency vs Zenith Angle (in1): East Cryostat");
   auto legendd = new TLegend(0.1,0.8,0.2,0.9);
   legendd->AddEntry(h1d,"MC");
   legendd->AddEntry(h2d,"Data");
   legendd->Draw();
   cnvs_z1->Update();


   TCanvas* cnvs_z0 = new TCanvas("cnvs_z0", "c1", 1,1,800,700);
   h1e->SetLineColor(kRed);
   h2e->SetLineColor(kBlue);
   hs_z0->Add(h1e);
   hs_z0->Add(h2e);
   hs_z0->Draw("nostackHIST");


   hs_z0->GetXaxis()->SetTitle(" Zenith Angle in radians ");
   hs_z0->GetYaxis()->SetTitle("Relative Frequency");
   TText Te; Te.SetTextFont(42); Te.SetTextAlign(21);
   Te.DrawTextNDC(.5,.95,"Relative Frequency vs Zenith Angle (in2): East Cryostat");
   auto legende = new TLegend(0.1,0.8,0.2,0.9);
   legende->AddEntry(h1e,"MC");
   legende->AddEntry(h2e,"Data");
   legende->Draw();
   cnvs_z0->Update();


   TCanvas* cnvs_q2 = new TCanvas("cnvs_q2", "c1", 1,1,800,700);
   h1f->SetLineColor(kRed);
   h2f->SetLineColor(kBlue);
   hs_q2->Add(h1f);
   hs_q2->Add(h2f);
   hs_q2->Draw("nostackHIST");


   hs_q2->GetXaxis()->SetTitle(" dQ/dx  ");
   hs_q2->GetYaxis()->SetTitle("Relative Frequency");
   TText Tf; Tf.SetTextFont(42); Tf.SetTextAlign(21);
   Tf.DrawTextNDC(.5,.95,"Relative Frequency vs dQ/dx (col): East Cryostat");
   auto legendf = new TLegend(0.1,0.8,0.2,0.9);
   legendf->AddEntry(h1f,"MC");
   legendf->AddEntry(h2f,"Data");
   legendf->Draw();
   cnvs_q2->Update();




   TCanvas* cnvs_q1 = new TCanvas("cnvs_q1", "c1", 1,1,800,700);
   h1g->SetLineColor(kRed);
   h2g->SetLineColor(kBlue);
   hs_q1->Add(h1g);
   hs_q1->Add(h2g);
   hs_q1->Draw("nostackHIST");

   hs_q1->GetXaxis()->SetTitle(" dQ/dx  ");
   hs_q1->GetYaxis()->SetTitle("Relative Frequency");
   TText Tg; Tg.SetTextFont(42); Tg.SetTextAlign(21);
   Tg.DrawTextNDC(.5,.95,"Relative Frequency vs dQ/dx (in1): East Cryostat");
   auto legendg = new TLegend(0.1,0.8,0.2,0.9);
   legendg->AddEntry(h1g,"MC");
   legendg->AddEntry(h2g,"Data");
   legendg->Draw();
   cnvs_q1->Update();


   TCanvas* cnvs_q0 = new TCanvas("cnvs_q0", "c1", 1,1,800,700);
   h1h->SetLineColor(kRed);
   h2h->SetLineColor(kBlue);
   hs_q0->Add(h1h);
   hs_q0->Add(h2h);
   hs_q0->Draw("nostackHIST");


   hs_q0->GetXaxis()->SetTitle(" dQ/dx  ");
   hs_q0->GetYaxis()->SetTitle("Relative Frequency");
   TText Th; Th.SetTextFont(42); Th.SetTextAlign(21);
   Th.DrawTextNDC(.5,.95,"Relative Frequency vs dQ/dx (in2): East Cryostat");
   auto legendh = new TLegend(0.1,0.8,0.2,0.9);
   legendh->AddEntry(h1h,"MC");
   legendh->AddEntry(h2h,"Data");
   legendh->Draw();
   cnvs_q0->Update();


   TCanvas* cnvs_r2 = new TCanvas("cnvs_r2", "c1", 1,1,800,700);
   h1i->SetLineColor(kRed);
   h2i->SetLineColor(kBlue);
   hs_r2->Add(h1i);
   hs_r2->Add(h2i);
   hs_r2->Draw("nostackHIST");

   hs_r2->GetXaxis()->SetTitle(" Residual Range in cm ");
   hs_r2->GetYaxis()->SetTitle("Relative Frequency");
   TText Ti; Ti.SetTextFont(42); Ti.SetTextAlign(21);
   Ti.DrawTextNDC(.5,.95,"Relative Frequency vs Residual Range (col): East Cryostat");
   auto legendi = new TLegend(0.1,0.8,0.2,0.9);
   legendi->AddEntry(h1i,"MC");
   legendi->AddEntry(h2i,"Data");
   legendi->Draw();
   cnvs_r2->Update();


   TCanvas* cnvs_r1 = new TCanvas("cnvs_r1", "c1", 1,1,800,700);
   h1j->SetLineColor(kRed);
   h2j->SetLineColor(kBlue);
   hs_r1->Add(h1j);
   hs_r1->Add(h2j);
   hs_r1->Draw("nostackHIST");


   hs_r1->GetXaxis()->SetTitle(" Residual Range in cm ");
   hs_r1->GetYaxis()->SetTitle("Relative Frequency");
   TText Tj; Tj.SetTextFont(42); Tj.SetTextAlign(21);
   Tj.DrawTextNDC(.5,.95,"Relative Frequency vs Residual Range (in1): East Cryostat");
   auto legendj = new TLegend(0.1,0.8,0.2,0.9);
   legendj->AddEntry(h1j,"MC");
   legendj->AddEntry(h2j,"Data");
   legendj->Draw();
   cnvs_r1->Update();


   TCanvas* cnvs_r0 = new TCanvas("cnvs_r0", "c1", 1,1,800,700);
   h1k->SetLineColor(kRed);
   h2k->SetLineColor(kBlue);
   hs_r0->Add(h1k);
   hs_r0->Add(h2k);
   hs_r0->Draw("nostackHIST");

   hs_r0->GetXaxis()->SetTitle(" Residual Range in cm ");
   hs_r0->GetYaxis()->SetTitle("Relative Frequency");
   TText Tk; Tk.SetTextFont(42); Tk.SetTextAlign(21);
   Tk.DrawTextNDC(.5,.95,"Relative Frequency vs Residual Range (in2): East Cryostat");
   auto legendk = new TLegend(0.1,0.8,0.2,0.9);
   legendk->AddEntry(h1k,"MC");
   legendk->AddEntry(h2k,"Data");
   legendk->Draw();
   cnvs_r0->Update();

   TCanvas* cnvs_l = new TCanvas("cnvs_l", "c1", 1,1,800,700);
   h1l->SetLineColor(kRed);
   h2l->SetLineColor(kBlue);
   hs_l->Add(h1l);
   hs_l->Add(h2l);
   hs_l->Draw("nostackHIST");


   hs_l->GetXaxis()->SetTitle(" Muon Length in cm  ");
   hs_l->GetYaxis()->SetTitle("Relative Frequency");
   TText Tl; Tl.SetTextFont(42); Tl.SetTextAlign(21);
   Tl.DrawTextNDC(.5,.95,"Relative Frequency vs Muon Length: East Cryostat");
   auto legendl = new TLegend(0.1,0.8,0.2,0.9);
   legendl->AddEntry(h1l,"MC");
   legendl->AddEntry(h2l,"Data");
   legendl->Draw();
   cnvs_l->Update();


   TCanvas* cnvs_t0 = new TCanvas("cnvs_t0", "c1", 1,1,800,700);
   h1m->SetLineColor(kRed);
   h2m->SetLineColor(kBlue);
   hs_t0->Add(h1m);
   hs_t0->Add(h2m);
   hs_t0->Draw("nostackHIST");

   hs_t0->GetXaxis()->SetTitle(" T0 in us  ");
   hs_t0->GetYaxis()->SetTitle("Relative Frequency");
   TText Tm; Tm.SetTextFont(42); Tm.SetTextAlign(21);
   Tm.DrawTextNDC(.5,.95,"Relative Frequency vs To: East Cryostat");
   auto legendm = new TLegend(0.1,0.8,0.2,0.9);
   legendm->AddEntry(h1m,"MC");
   legendm->AddEntry(h2m,"Data");
   legendm->Draw();
   cnvs_t0->Update();



   TCanvas* cnvs_sx = new TCanvas("cnvs_sx", "c1", 1,1,800,700);
   h1n->SetLineColor(kRed);
   h2n->SetLineColor(kBlue);
   hs_sx->Add(h1n);
   hs_sx->Add(h2n);
   hs_sx->Draw("nostackHIST");


   hs_sx->GetXaxis()->SetTitle(" Track Start (X) in cm  ");
   hs_sx->GetYaxis()->SetTitle("Relative Frequency");
   TText Tn; Tn.SetTextFont(42); Tn.SetTextAlign(21);
   Tn.DrawTextNDC(.5,.95,"Relative Frequency vs Track Start (X): East Cryostat");
   auto legendn = new TLegend(0.1,0.8,0.2,0.9);
   legendn->AddEntry(h1n,"MC");
   legendn->AddEntry(h2n,"Data");
   legendn->Draw();
   cnvs_sx->Update();


   TCanvas* cnvs_sy = new TCanvas("cnvs_sy", "c1", 1,1,800,700);
   h1o->SetLineColor(kRed);
   h2o->SetLineColor(kBlue);
   hs_sy->Add(h1o);
   hs_sy->Add(h2o);
   hs_sy->Draw("nostackHIST");

   hs_sy->GetXaxis()->SetTitle(" Track Start (Y) in cm  ");
   hs_sy->GetYaxis()->SetTitle("Relative Frequency");
   TText To; To.SetTextFont(42); To.SetTextAlign(21);
   To.DrawTextNDC(.5,.95,"Relative Frequency vs Track Start (Y): East Cryostat");
   auto legendo = new TLegend(0.1,0.8,0.2,0.9);
   legendo->AddEntry(h1o,"MC");
   legendo->AddEntry(h2o,"Data");
   legendo->Draw();
   cnvs_sy->Update();


   TCanvas* cnvs_sz = new TCanvas("cnvs_sz", "c1", 1,1,800,700);
   h1p->SetLineColor(kRed);
   h2p->SetLineColor(kBlue);
   hs_sz->Add(h1p);
   hs_sz->Add(h2p);
   hs_sz->Draw("nostackHIST");

   hs_sz->GetXaxis()->SetTitle(" Track Start (Z) in cm  ");
   hs_sz->GetYaxis()->SetTitle("Relative Frequency");
   TText Tp; Tp.SetTextFont(42); Tp.SetTextAlign(21);
   Tp.DrawTextNDC(.5,.95,"Relative Frequency vs Track Start (Z): East Cryostat");
   auto legendp = new TLegend(0.1,0.8,0.2,0.9);
   legendp->AddEntry(h1p,"MC");
   legendp->AddEntry(h2p,"Data");
   legendp->Draw();
   cnvs_sz->Update();



   TCanvas* cnvs_ex = new TCanvas("cnvs_ex", "c1", 1,1,800,700);
   h1q->SetLineColor(kRed);
   h2q->SetLineColor(kBlue);
   hs_ex->Add(h1q);
   hs_ex->Add(h2q);
   hs_ex->Draw("nostackHIST");


   hs_ex->GetXaxis()->SetTitle(" Track End (X) in cm  ");
   hs_ex->GetYaxis()->SetTitle("Relative Frequency");
   TText Tq; Tq.SetTextFont(42); Tq.SetTextAlign(21);
   Tq.DrawTextNDC(.5,.95,"Relative Frequency vs Track End (X): East Cryostat");
   auto legendq = new TLegend(0.1,0.8,0.2,0.9);
   legendq->AddEntry(h1q,"MC");
   legendq->AddEntry(h2q,"Data");
   legendq->Draw();
   cnvs_ex->Update();


   TCanvas* cnvs_ey = new TCanvas("cnvs_ey", "c1", 1,1,800,700);
   h1r->SetLineColor(kRed);
   h2r->SetLineColor(kBlue);
   hs_ey->Add(h1r);
   hs_ey->Add(h2r);
   hs_ey->Draw("nostackHIST");


   hs_ey->GetXaxis()->SetTitle(" Track End (Y) in cm  ");
   hs_ey->GetYaxis()->SetTitle("Relative Frequency");
   TText Tr; Tr.SetTextFont(42); Tr.SetTextAlign(21);
   Tr.DrawTextNDC(.5,.95,"Relative Frequency vs Track End (Y): East Cryostat");
   auto legendr = new TLegend(0.1,0.8,0.2,0.9);
   legendr->AddEntry(h1r,"MC");
   legendr->AddEntry(h2r,"Data");
   legendr->Draw();
   cnvs_ey->Update();


   TCanvas* cnvs_ez = new TCanvas("cnvs_ez", "c1", 1,1,800,700);
   h1s->SetLineColor(kRed);
   h2s->SetLineColor(kBlue);
   hs_ez->Add(h1s);
   hs_ez->Add(h2s);
   hs_ez->Draw("nostackHIST");


   hs_ez->GetXaxis()->SetTitle(" Track End (Z) in cm  ");
   hs_ez->GetYaxis()->SetTitle("Relative Frequency");
   TText Ts; Ts.SetTextFont(42); Ts.SetTextAlign(21);
   Ts.DrawTextNDC(.5,.95,"Relative Frequency vs Track End (Z): East Cryostat");
   auto legends = new TLegend(0.1,0.8,0.2,0.9);
   legends->AddEntry(h1s,"MC");
   legends->AddEntry(h2s,"Data");
   legends->Draw();
   cnvs_ez->Update();
   cout<<"plots done"<<endl;

   cout<<"end of macro"<<endl;


}

   
     // alternative way to do it :)
   //   h2->DrawNormalized();
   // h2->DrawNormalized("same");
   

   //cnvs_az2->Update();
   /*
    hs_az2->GetXaxis()->SetTitle(" Azimuthal Angle in radians ");
    hs_az2->GetYaxis()->SetTitle("Relative Frequency");
    TText T; T.SetTextFont(42); T.SetTextAlign(21);
    T.DrawTextNDC(.5,.95,"Relative Frequency vs Azimuthal Angle (col): East Cryostat");
    auto legend = new TLegend(0.1,0.8,0.2,0.9);
    legend->AddEntry(h1,"MC");
    legend->AddEntry(h2,"Data");
    legend->Draw();
    cnvs_az2->Update();


    hs_az1->GetXaxis()->SetTitle(" Azimuthal Angle in radians ");
    hs_az1->GetYaxis()->SetTitle("Relative Frequency");
    TText Ta; Ta.SetTextFont(42); Ta.SetTextAlign(21);
    Ta.DrawTextNDC(.5,.95,"Relative Frequency vs Azimuthal Angle (in1): East Cryostat");
    auto legenda = new TLegend(0.1,0.8,0.2,0.9);
    legenda->AddEntry(h1a,"MC");
    legenda->AddEntry(h2a,"Data");
    legenda->Draw();
    cnvs_az1->Update();


    hs_az0->GetXaxis()->SetTitle(" Azimuthal Angle in radians ");
    hs_az0->GetYaxis()->SetTitle("Relative Frequency");
    TText Tb; Tb.SetTextFont(42); Tb.SetTextAlign(21);
    Tb.DrawTextNDC(.5,.95,"Relative Frequency vs Azimuthal Angle (in2): East Cryostat");
    auto legendb = new TLegend(0.1,0.8,0.2,0.9);
    legendb->AddEntry(h1b,"MC");
    legendb->AddEntry(h2b,"Data");
    legendb->Draw();
    cnvs_az0->Update();

   



    hs_z2->GetXaxis()->SetTitle(" Zenith Angle in radians ");
    hs_z2->GetYaxis()->SetTitle("Relative Frequency");
    TText Tc; Tc.SetTextFont(42); Tc.SetTextAlign(21);
    Tc.DrawTextNDC(.5,.95,"Relative Frequency vs Zenith Angle (col): East Cryostat");
    auto legendc = new TLegend(0.1,0.8,0.2,0.9);
    legendc->AddEntry(h1c,"MC");
    legendc->AddEntry(h2c,"Data");
    legendc->Draw();
    cnvs_z2->Update();

    hs_z1->GetXaxis()->SetTitle(" Zenith Angle in radians ");
    hs_z1->GetYaxis()->SetTitle("Relative Frequency");
    TText Td; Td.SetTextFont(42); Td.SetTextAlign(21);
    Td.DrawTextNDC(.5,.95,"Relative Frequency vs Zenith Angle (in1): East Cryostat");
    auto legendd = new TLegend(0.1,0.8,0.2,0.9);
    legendd->AddEntry(h1d,"MC");
    legendd->AddEntry(h2d,"Data");
    legendd->Draw();
    cnvs_z1->Update();

    hs_z0->GetXaxis()->SetTitle(" Zenith Angle in radians ");
    hs_z0->GetYaxis()->SetTitle("Relative Frequency");
    TText Te; Te.SetTextFont(42); Te.SetTextAlign(21);
    Te.DrawTextNDC(.5,.95,"Relative Frequency vs Zenith Angle (in2): East Cryostat");
    auto legende = new TLegend(0.1,0.8,0.2,0.9);
    legende->AddEntry(h1e,"MC");
    legende->AddEntry(h2e,"Data");
    legende->Draw();
    cnvs_z0->Update();






    hs_r2->GetXaxis()->SetTitle(" Residual Range in cm ");
    hs_r2->GetYaxis()->SetTitle("Relative Frequency");
    TText Tf; Tf.SetTextFont(42); Tf.SetTextAlign(21);
    Tf.DrawTextNDC(.5,.95,"Relative Frequency vs Residual Range (col): East Cryostat");
    auto legendf = new TLegend(0.1,0.8,0.2,0.9);
    legendf->AddEntry(h1f,"MC");
    legendf->AddEntry(h2f,"Data");
    legendf->Draw();
    cnvs_r2->Update();

    hs_r1->GetXaxis()->SetTitle(" Residual Range in cm ");
    hs_r1->GetYaxis()->SetTitle("Relative Frequency");
    TText Tg; Tg.SetTextFont(42); Tg.SetTextAlign(21);
    Tg.DrawTextNDC(.5,.95,"Relative Frequency vs Residual Range (in1): East Cryostat");
    auto legendg = new TLegend(0.1,0.8,0.2,0.9);
    legendg->AddEntry(h1g,"MC");
    legendg->AddEntry(h2g,"Data");
    legendg->Draw();
    cnvs_r1->Update();

    hs_r0->GetXaxis()->SetTitle(" Residual Range in cm ");
    hs_r0->GetYaxis()->SetTitle("Relative Frequency");
    TText Th; Th.SetTextFont(42); Th.SetTextAlign(21);
    Th.DrawTextNDC(.5,.95,"Relative Frequency vs Residual Range (in2): East Cryostat");
    auto legendh = new TLegend(0.1,0.8,0.2,0.9);
    legendh->AddEntry(h1h,"MC");
    legendh->AddEntry(h2h,"Data");
    legendh->Draw();
    cnvs_r0->Update();


    hs_q2->GetXaxis()->SetTitle(" dQ/dx  ");
    hs_q2->GetYaxis()->SetTitle("Relative Frequency");
    TText Ti; Ti.SetTextFont(42); Ti.SetTextAlign(21);
    Ti.DrawTextNDC(.5,.95,"Relative Frequency vs dQ/dx (col): East Cryostat");
    auto legendi = new TLegend(0.1,0.8,0.2,0.9);
    legendi->AddEntry(h1i,"MC");
    legendi->AddEntry(h2i,"Data");
    legendi->Draw();
    cnvs_q2->Update();

    hs_q1->GetXaxis()->SetTitle(" dQ/dx  ");
    hs_q1->GetYaxis()->SetTitle("Relative Frequency");
    TText Tj; Tj.SetTextFont(42); Tj.SetTextAlign(21);
    Tj.DrawTextNDC(.5,.95,"Relative Frequency vs dQ/dx (in1): East Cryostat");
    auto legendj = new TLegend(0.1,0.8,0.2,0.9);
    legendj->AddEntry(h1j,"MC");
    legendj->AddEntry(h2j,"Data");
    legendj->Draw();
    cnvs_q1->Update();

    hs_q0->GetXaxis()->SetTitle(" dQ/dx  ");
    hs_q0->GetYaxis()->SetTitle("Relative Frequency");
    TText Tk; Tk.SetTextFont(42); Tk.SetTextAlign(21);
    Tk.DrawTextNDC(.5,.95,"Relative Frequency vs dQ/dx (in2): East Cryostat");
    auto legendk = new TLegend(0.1,0.8,0.2,0.9);
    legendk->AddEntry(h1k,"MC");
    legendk->AddEntry(h2k,"Data");
    legendk->Draw();
    cnvs_q0->Update();

   



    hs_l->GetXaxis()->SetTitle(" Muon Length in cm  ");
    hs_l->GetYaxis()->SetTitle("Relative Frequency");
    TText Tl; Tl.SetTextFont(42); Tl.SetTextAlign(21);
    Tl.DrawTextNDC(.5,.95,"Relative Frequency vs Muon Length: East Cryostat");
    auto legendl = new TLegend(0.1,0.8,0.2,0.9);
    legendl->AddEntry(h1l,"MC");
    legendl->AddEntry(h2l,"Data");
    legendl->Draw();
    cnvs_l->Update();

    hs_t0->GetXaxis()->SetTitle(" T0 in us  ");
    hs_t0->GetYaxis()->SetTitle("Relative Frequency");
    TText Tm; Tm.SetTextFont(42); Tm.SetTextAlign(21);
    Tm.DrawTextNDC(.5,.95,"Relative Frequency vs To: East Cryostat");
    auto legendm = new TLegend(0.1,0.8,0.2,0.9);
    legendm->AddEntry(h1m,"MC");
    legendm->AddEntry(h2m,"Data");
    legendm->Draw();
    cnvs_t0->Update();
   

    hs_sx->GetXaxis()->SetTitle(" Track Start (X) in cm  ");
    hs_sx->GetYaxis()->SetTitle("Relative Frequency");
    TText Tn; Tn.SetTextFont(42); Tn.SetTextAlign(21);
    Tn.DrawTextNDC(.5,.95,"Relative Frequency vs Track Start (X): East Cryostat");
    auto legendn = new TLegend(0.1,0.8,0.2,0.9);
    legendn->AddEntry(h1n,"MC");
    legendn->AddEntry(h2n,"Data");
    legendn->Draw();
    cnvs_sx->Update();


    hs_sy->GetXaxis()->SetTitle(" Track Start (Y) in cm  ");
    hs_sy->GetYaxis()->SetTitle("Relative Frequency");
    TText To; To.SetTextFont(42); To.SetTextAlign(21);
    To.DrawTextNDC(.5,.95,"Relative Frequency vs Track Start (Y): East Cryostat");
    auto legendo = new TLegend(0.1,0.8,0.2,0.9);
    legendo->AddEntry(h1o,"MC");
    legendo->AddEntry(h2o,"Data");
    legendo->Draw();
    cnvs_sy->Update();

    hs_sz->GetXaxis()->SetTitle(" Track Start (Z) in cm  ");
    hs_sz->GetYaxis()->SetTitle("Relative Frequency");
    TText Tp; Tp.SetTextFont(42); Tp.SetTextAlign(21);
    Tp.DrawTextNDC(.5,.95,"Relative Frequency vs Track Start (Z): East Cryostat");
    auto legendp = new TLegend(0.1,0.8,0.2,0.9);
    legendp->AddEntry(h1p,"MC");
    legendp->AddEntry(h2p,"Data");
    legendp->Draw();
    cnvs_sz->Update();


    hs_ex->GetXaxis()->SetTitle(" Track End (X) in cm  ");
    hs_ex->GetYaxis()->SetTitle("Relative Frequency");
    TText Tq; Tq.SetTextFont(42); Tq.SetTextAlign(21);
    Tq.DrawTextNDC(.5,.95,"Relative Frequency vs Track End (X): East Cryostat");
    auto legendq = new TLegend(0.1,0.8,0.2,0.9);
    legendq->AddEntry(h1q,"MC");
    legendq->AddEntry(h2q,"Data");
    legendq->Draw();
    cnvs_ex->Update();

    hs_ey->GetXaxis()->SetTitle(" Track End (Y) in cm  ");
    hs_ey->GetYaxis()->SetTitle("Relative Frequency");
    TText Tr; Tr.SetTextFont(42); Tr.SetTextAlign(21);
    Tr.DrawTextNDC(.5,.95,"Relative Frequency vs Track End (Y): East Cryostat");
    auto legendr = new TLegend(0.1,0.8,0.2,0.9);
    legendr->AddEntry(h1r,"MC");
    legendr->AddEntry(h2r,"Data");
    legendr->Draw();
    cnvs_ey->Update();

    hs_ez->GetXaxis()->SetTitle(" Track End (Z) in cm  ");
    hs_ez->GetYaxis()->SetTitle("Relative Frequency");
    TText Ts; Ts.SetTextFont(42); Ts.SetTextAlign(21);
    Ts.DrawTextNDC(.5,.95,"Relative Frequency vs Track End (Z): East Cryostat");
    auto legends = new TLegend(0.1,0.8,0.2,0.9);
    legends->AddEntry(h1s,"MC");
    legends->AddEntry(h2s,"Data");
    legends->Draw();
    cnvs_ez->Update();
*/

