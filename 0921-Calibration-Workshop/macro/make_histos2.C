#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

void make_histos2(bool verbose=false) {


  gStyle->SetOptStat(0);


  //  TCanvas* cnvs_az2 = new TCanvas("cnvs_az2", "c1", 1,1,800,700);   
  THStack *hs_az2 = new THStack("hs_az2","");
  //TCanvas* cnvs_z2 = new TCanvas("cnvs_z2", "c1", 1,1,800,700);
  THStack *hs_zz2 = new THStack("hs_zz2","");
  //TCanvas* cnvs_az1 = new TCanvas("cnvs_az1", "c1", 1,1,800,700);
  THStack *hs_az1 = new THStack("hs_az1","");
  //TCanvas* cnvs_z1 = new TCanvas("cnvs_z1", "c1", 1,1,800,700);
  THStack *hs_zz1 = new THStack("hs_zz1","");
  //TCanvas* cnvs_az0 = new TCanvas("cnvs_az0", "c1", 1,1,800,700);
  THStack *hs_az0 = new THStack("hs_az0","");
  //TCanvas* cnvs_z0 = new TCanvas("cnvs_z0", "c1", 1,1,800,700);
  THStack *hs_zz0 = new THStack("hs_zz0","");
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

  THStack *hs_ci0 = new THStack("hs_ci0","");
  THStack *hs_ci1 = new THStack("hs_ci1","");
  THStack *hs_ci2 = new THStack("hs_ci2","");

  THStack *hs_wi0 = new THStack("hs_wi0","");
  THStack *hs_wi1 = new THStack("hs_wi1","");
  THStack *hs_wi2 = new THStack("hs_wi2","");

  THStack *hs_w0 = new THStack("hs_w0","");
  THStack *hs_w1 = new THStack("hs_w1","");
  THStack *hs_w2 = new THStack("hs_w2","");

  THStack *hs_ti0 = new THStack("hs_ti0","");
  THStack *hs_ti1 = new THStack("hs_ti1","");
  THStack *hs_ti2 = new THStack("hs_ti2","");

  THStack *hs_x0 = new THStack("hs_x0","");
  THStack *hs_x1 = new THStack("hs_x1","");
  THStack *hs_x2 = new THStack("hs_x2","");

  THStack *hs_y0 = new THStack("hs_y0","");
  THStack *hs_y1 = new THStack("hs_y1","");
  THStack *hs_y2 = new THStack("hs_y2","");

  THStack *hs_z0 = new THStack("hs_z0","");
  THStack *hs_z1 = new THStack("hs_z1","");
  THStack *hs_z2 = new THStack("hs_z2","");

  THStack *hs_p0 = new THStack("hs_p0","");
  THStack *hs_p1 = new THStack("hs_p1","");
  THStack *hs_p2 = new THStack("hs_p2","");


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




  TH1F *h_ci0_mc   = new TH1F("h_ci0_mc","Relative Frequency vs  Charge Integral: East Cryostat", 10., 0., 10.);//-100000., 100000.);
  TH1F *h_ci0_data = new TH1F("h_ci0_data","Relative Frequency vs Charge Integral: East Cryostat", 10., 0., 10.);//-100000., 100000.);
  h_ci0_mc->GetXaxis()->SetTitle(" Charge Integral in ADC ");
  h_ci0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_ci1_mc   = new TH1F("h_ci1_mc","Relative Frequency vs  Charge Integral: East Cryostat", 10., 0., 10.);//-100000., 100000.);
  TH1F *h_ci1_data = new TH1F("h_ci1_data","Relative Frequency vs Charge Integral: East Cryostat", 10., 0., 10.);//-100000., 100000.);
  h_ci1_mc->GetXaxis()->SetTitle(" Charge Integral in ADC ");
  h_ci1_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_ci2_mc   = new TH1F("h_ci2_mc","Relative Frequency vs  Charge Integral: East Cryostat", 10., 0., 10.);//-100000., 100000.);
  TH1F *h_ci2_data = new TH1F("h_ci2_data","Relative Frequency vs Charge Integral: East Cryostat", 10., 0., 10.);//-100000., 100000.);
  h_ci2_mc->GetXaxis()->SetTitle(" Charge Integral in ADC ");
  h_ci2_mc->GetYaxis()->SetTitle("Relative Frequency");






  TH1F *h_wi0_mc   = new TH1F("h_wi0_mc","Relative Frequency vs  Width: East Cryostat", 100., 0., 100.);//-100000., 100000.);
  TH1F *h_wi0_data = new TH1F("h_wi0_data","Relative Frequency vs Width: East Cryostat", 100., 0., 100.);//-100000., 100000.);
  h_wi0_mc->GetXaxis()->SetTitle(" Width in ticks");
  h_wi0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_wi1_mc   = new TH1F("h_wi1_mc","Relative Frequency vs  Width: East Cryostat", 100., 0., 100.);//-100000., 100000.);
  TH1F *h_wi1_data = new TH1F("h_wi1_data","Relative Frequency vs Width: East Cryostat", 100., 0., 100.);//-100000., 100000.);
  h_wi1_mc->GetXaxis()->SetTitle(" Width in ticks");
  h_wi1_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_wi2_mc   = new TH1F("h_wi2_mc","Relative Frequency vs  Width: East Cryostat", 100., 0., 100.);// -100000., 100000.);
  TH1F *h_wi2_data = new TH1F("h_wi2_data","Relative Frequency vs Width: East Cryostat", 100., 0., 100.);// -100000., 100000.);
  h_wi2_mc->GetXaxis()->SetTitle(" Width in ticks");
  h_wi2_mc->GetYaxis()->SetTitle("Relative Frequency");




  TH1F *h_w0_mc   = new TH1F("h_w0_mc","Relative Frequency vs  Wire: East Cryostat", 100., 0., 100.);//-100., 100.);
  TH1F *h_w0_data = new TH1F("h_w0_data","Relative Frequency vs Wire: East Cryostat", 100., 0., 100.);//-100., 100.);
  h_w0_mc->GetXaxis()->SetTitle(" Wire Number");
  h_w0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_w1_mc   = new TH1F("h_w1_mc","Relative Frequency vs  Wire: East Cryostat", 100.,0., 100.);// -100000., 100000.);
  TH1F *h_w1_data = new TH1F("h_w1_data","Relative Frequency vs Wire: East Cryostat", 100.,0., 100.);// -100000., 100000.);
  h_w1_mc->GetXaxis()->SetTitle(" Wire Number");
  h_w1_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_w2_mc   = new TH1F("h_w2_mc","Relative Frequency vs  Wire: East Cryostat", 100., 0., 100.);//-100000., 100000.);
  TH1F *h_w2_data = new TH1F("h_w2_data","Relative Frequency vs Wire: East Cryostat", 100., 0., 100.);//-100000., 100000.);
  h_w2_mc->GetXaxis()->SetTitle(" Wire Number");
  h_w2_mc->GetYaxis()->SetTitle("Relative Frequency");



  TH1F *h_ti0_mc   = new TH1F("h_ti0_mc","Relative Frequency vs  Time: East Cryostat", 100., -100000., 100000.); //-1000., 100.);
  TH1F *h_ti0_data = new TH1F("h_ti0_data","Relative Frequency vs Time: East Cryostat", 100., -100000., 100000.); //0., 100.);// -100000., 100000.);
  h_ti0_mc->GetXaxis()->SetTitle(" Time in ticks");
  h_ti0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_ti1_mc   = new TH1F("h_ti1_mc","Relative Frequency vs  Time: East Cryostat", 100., -100000., 100000.); //0., 100.);//-100000., 100000.);
  TH1F *h_ti1_data = new TH1F("h_ti1_data","Relative Frequency vs Time: East Cryostat", 100.,-100000., 100000.); // 0., 100.);//-100000., 100000.);
  h_ti1_mc->GetXaxis()->SetTitle(" Time in ticks");
  h_ti1_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_ti2_mc   = new TH1F("h_ti2_mc","Relative Frequency vs  Time: East Cryostat", 100., -100000., 100000.); //0., 100.);//-100000., 100000.);
  TH1F *h_ti2_data = new TH1F("h_ti2_data","Relative Frequency vs Time: East Cryostat", 100., -100000., 100000.); //0., 100.);//-100000., 100000.);
  h_ti2_mc->GetXaxis()->SetTitle(" Time in ticks");
  h_ti2_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_x0_mc   = new TH1F("h_x0_mc","Relative Frequency vs  Direction (X): East Cryostat", 100., -10., 10.);// -100000., 100000.);
  TH1F *h_x0_data = new TH1F("h_x0_data","Relative Frequency vs Direction (X): East Cryostat", 100., -10., 10.);//-100000., 100000.);
  h_x0_mc->GetXaxis()->SetTitle(" Direction (X) in cm");
  h_x0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_x1_mc   = new TH1F("h_x1_mc","Relative Frequency vs  Direction (X): East Cryostat", 100., -10., 10.);//-100000., 100000.);
  TH1F *h_x1_data = new TH1F("h_x1_data","Relative Frequency vs Direction (X): East Cryostat", 100., -10., 10.);//-100000., 100000.);
  h_x1_mc->GetXaxis()->SetTitle(" Direction (X) in cm");
  h_x1_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_x2_mc   = new TH1F("h_x2_mc","Relative Frequency vs  Direction (X): East Cryostat", 100., -10., 10.);//-100000., 100000.);
  TH1F *h_x2_data = new TH1F("h_x2_data","Relative Frequency vs Direction (X): East Cryostat", 100., -10., 10.);//-100000., 100000.);
  h_x2_mc->GetXaxis()->SetTitle(" Direction (X) in cm");
  h_x2_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_y0_mc   = new TH1F("h_y0_mc","Relative Frequency vs  Direction (Y): East Cryostat", 100., -10., 10.);//-100000., 100000.);
  TH1F *h_y0_data = new TH1F("h_y0_data","Relative Frequency vs Direction (Y): East Cryostat", 100., -10., 10.);//-100000., 100000.);
  h_y0_mc->GetXaxis()->SetTitle(" Direction (Y) in cm");
  h_y0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_y1_mc   = new TH1F("h_y1_mc","Relative Frequency vs  Direction (Y): East Cryostat", 100., -10., 10.);//-100000., 100000.);
  TH1F *h_y1_data = new TH1F("h_y1_data","Relative Frequency vs Direction (Y): East Cryostat", 100., -10., 10.);//-100000., 100000.);
  h_y1_mc->GetXaxis()->SetTitle(" Direction (Y) in cm");
  h_y1_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_y2_mc   = new TH1F("h_y2_mc","Relative Frequency vs  Direction (Y): East Cryostat", 100., -10., 10.);//-100000., 100000.);
  TH1F *h_y2_data = new TH1F("h_y2_data","Relative Frequency vs Direction (Y): East Cryostat", 100., -10., 10.);//-100000., 100000.);
  h_y2_mc->GetXaxis()->SetTitle(" Direction (Y) in cm");
  h_y2_mc->GetYaxis()->SetTitle("Relative Frequency");



  TH1F *h_z0_mc   = new TH1F("h_z0_mc","Relative Frequency vs  Direction (Z): East Cryostat", 100., -10., 10.);//-100000., 100000.);
  TH1F *h_z0_data = new TH1F("h_z0_data","Relative Frequency vs Direction (Z): East Cryostat", 100., -10., 10.);//-100000., 100000.);
  h_z0_mc->GetXaxis()->SetTitle(" Direction (Z) in cm");
  h_z0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_z1_mc   = new TH1F("h_z1_mc","Relative Frequency vs  Direction (Z): East Cryostat", 100., -10., 10.);//-100000., 100000.);
  TH1F *h_z1_data = new TH1F("h_z1_data","Relative Frequency vs Direction (Z): East Cryostat", 100., -10., 10.);//-100000., 100000.);
  h_z1_mc->GetXaxis()->SetTitle(" Direction (Z) in cm");
  h_z1_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_z2_mc   = new TH1F("h_z2_mc","Relative Frequency vs  Direction (Z): East Cryostat", 100., -10., 10.);//-100000., 100000.);
  TH1F *h_z2_data = new TH1F("h_z2_data","Relative Frequency vs Direction (Z): East Cryostat", 100., -10., 10.);//-100000., 100000.);
  h_z2_mc->GetXaxis()->SetTitle(" Direction (Z) in cm");
  h_z2_mc->GetYaxis()->SetTitle("Relative Frequency");



  TH1F *h_p0_mc   = new TH1F("h_p0_mc","Relative Frequency vs  Pitch: East Cryostat", 100., -1000., 1000.);
  TH1F *h_p0_data = new TH1F("h_p0_data","Relative Frequency vs Pitch: East Cryostat", 100., -1000., 1000.);
  h_p0_mc->GetXaxis()->SetTitle(" Pitch in cm");
  h_p0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_p1_mc   = new TH1F("h_p1_mc","Relative Frequency vs  Pitch: East Cryostat", 100., -1000., 1000.);
  TH1F *h_p1_data = new TH1F("h_p1_data","Relative Frequency vs Pitch: East Cryostat", 100., -1000., 1000.);
  h_p1_mc->GetXaxis()->SetTitle(" Pitch in cm");
  h_p1_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_p2_mc   = new TH1F("h_p2_mc","Relative Frequency vs Pitch: East Cryostat", 100., -1000., 1000.);
  TH1F *h_p2_data = new TH1F("h_p2_data","Relative Frequency vs Pitch: East Cryostat", 100., -1000., 1000.);
  h_p2_mc->GetXaxis()->SetTitle(" Pitch in cm");
  h_p2_mc->GetYaxis()->SetTitle("Relative Frequency");





  cout<<"histos"<<endl;
  //create other histograms here!


   //Get the files from ICARUS gpvm
  TFileCollection *my_files = new TFileCollection("my_files","My File List");
  my_files->Add("/pnfs/icarus/persistent/calibration/calib_ntuples/mc/ICARUS_BNB_Nu_Cosmics/*.root");//

  //*.root");

//ICARUS_NuMI_Nu_Cosmics/hist_prodcorsika_genie_protononly_icarus_numi_*.root");///icarus/data/users/obitter/CalibrationWS21/hist_prodcorsika_genie_protononly_icarus_numi*.root");//  /pnfs/icarus/persistent/calibration/calib_ntuples/mc/ICARUS_NuMI_Nu_Cosmics/hist_prodcorsika_genie_protononly_icarus_numi_*.root);//volDetEnclosure_tpc_gen_filter_g4_detsim_48288511_90_reco1_20210912T095950_reco2.root");///icarus/data/users/obitter/CalibrationWS21/hist_prodcorsika_genie_protononly_icarus_numi_volDetEnclosure_tpc_gen_filter_g4_detsim_48288511_9_reco1_20210912T103409_reco2.root");//*.root");

///pnfs/icarus/persistent/calibration/calib_ntuples/mc/ICARUS_NuMI_Nu_Cosmics/hist_prodcorsika_genie_protononly_icarus_numi_volDetEnclosure_tpc_gen_filter_g4_detsim_48288511*.root");//24037195*.root");   ///icarus/data/users/obitter/CalibrationWS21/hist_prodcorsika_genie_protononly_icarus_numi*.root");//_volDetEnclosure_tpc_gen_filter_g4_detsim_48288511_9_reco1_20210912T103409_reco2.root");//hist_prodcorsika_genie_protononly_icarus_numi*.root");//    
  ///pnfs/icarus/persistent/calibration/calib_ntuples/mc/ICARUS_NuMI_Nu_Cosmics/hist*.root"); 
  //  /icarus/data/users/obitter/CalibrationWS21/hist_prodcorsika_genie_protononly_icarus_numi*.root");//
///pnfs/icarus/persistent/calibration/calib_ntuples/mc/ICARUS_NuMI_Nu_Cosmics/
//hist_prodcorsika_genie_protononly_icarus_numi*.root");//hist_prodcorsika_genie_protononly_icarus_numi_volDetEnclosure_tpc_gen_filter_g4_detsim_48288511_9_reco1_20210912T103409_reco2.root");//hist*.root");
  std::cout << "Number of files in our MC list is " << my_files->GetNFiles() << std::endl;
  TChain myfile("caloskimE/TrackCaloSkim");
  myfile.AddFileInfoList(my_files->GetList());

  TFileCollection *my_files2 = new TFileCollection("my_files2","My File List2");
  my_files2->Add("/icarus/data/users/obitter/CalibrationWS21/*BNB*.root");

///pnfs/icarus/persistent/calibration/calib_ntuples/data/*BNB*run5*.root");//*BNB*run6100*.root");//*BNB*.root");///icarus/data/users/obitter/CalibrationWS21/hist_data_dl4_fstrm*.root");///pnfs/icarus/persistent/calibration/calib_ntuples/data/hist_data_dl4_fstrmNUMI_*.root);//run6100_8_20210624T222802_20210810T173022_stage0_20210811T172950_stage1-aaf73d30-50ca-4661-a655-5e11616b005d.root");///pnfs/icarus/persistent/calibration/calib_ntuples/data/hist_data_dl4_fstrmNUMI_run6106_3_20210626T110945_20210812T034226_stage0_20210812T113610_stage1-2f1b69b2-5063-44e9-a1d2-129b4cb99fed.root");///pnfs/icarus/persistent/calibration/calib_ntuples/data/hist_data_dl4_fstrmNUMI_run6106_7_20210626T122720_20210812T011952_stage0_20210812T120934_stage1-8dc3d211-6be0-4580-b340-9b68768e98f5.root");

///icarus/data/users/obitter/CalibrationWS21/hist_data_dl4_fstrmNUMI_run6106_50_20210627T040512_20210812T023813_stage0_20210812T121941_stage1-008e44f5-2b5f-49f3-9bf3-927a0c4bd7c1.root");   //*.root");
// /icarus/data/users/obitter/CalibrationWS21/hist_data_dl4_fstrmNUMI*.root");/icarus/data/users/obitter/CalibrationWS21/hist_data_dl4_fstrmNUMI*.root");

///pnfs/icarus/persistent/calibration/calib_ntuples/data/hist_data_dl4_fstrmNUMI*.root");//hist*.root"); ///icarus/data/users/obitter/CalibrationWS21/hist_data*NUMI*.root");//_dl4_fstrmNUMI_run6106_50_20210627T040512_20210812T023813_stage0_20210812T121941_stage1-008e44f5-2b5f-49f3-9bf3-927a0c4bd7c1.root");

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
   int b = 0;
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
     cout<<"track "<<a<<endl;
     if(*selected != 0) continue; //if not stopping, move one.
     //if(*tpc2 != 0) continue;
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

     if(tpc_c[last_i]==1) continue;

     h_azangle2_mc->Fill( TMath::ATan(x_c[last_i]/z_c[last_i]) );
     h_zangle2_mc->Fill( TMath::ATan(abs( (sqrt(x_c[last_i]*x_c[last_i] + y_c[last_i]*y_c[last_i]))) / (z_c[last_i]) ) );
     h_q2_mc->Fill(dqdx_c[last_i]);
     h_r2_mc->Fill(rr_c[last_i]);


     h_ci2_mc->Fill(integral_c[last_i]);
     h_wi2_mc->Fill(width_c[last_i]);
     h_w2_mc->Fill(wire_c[last_i]);
     h_ti2_mc->Fill(time_c[last_i]);
     h_x2_mc->Fill(x_c[last_i]);
     h_y2_mc->Fill(y_c[last_i]);
     h_z2_mc->Fill(z_c[last_i]);
     h_p2_mc->Fill(pitch_c[last_i]);



     cout<<"collection done"<<endl;

     //     if(verbose) 
     // cout << "MC angle " << TMath::ATan(x_c[last_i]/z_c[last_i]) << endl;

     //and fill all the other histograms related to traj points too
     

     if(ontraj_i2[last_j]!=1) continue;

     if(tpc_i2[last_j]==1) continue;

     h_azangle1_mc->Fill( TMath::ATan(x_i2[last_j]/z_i2[last_j]) );
     h_zangle1_mc->Fill( TMath::ATan(abs( (sqrt(x_i2[last_j]*x_i2[last_j] + y_i2[last_j]*y_i2[last_j]))) / (z_i2[last_j]) ) );
     h_q1_mc->Fill(dqdx_i2[last_j]);
     h_r1_mc->Fill(rr_i2[last_j]);

     h_ci1_mc->Fill(integral_i2[last_j]);
     h_wi1_mc->Fill(width_i2[last_j]);
     h_w1_mc->Fill(wire_i2[last_j]);
     h_ti1_mc->Fill(time_i2[last_j]);
     h_x1_mc->Fill(x_i2[last_j]);
     h_y1_mc->Fill(y_i2[last_j]);
     h_z1_mc->Fill(z_i2[last_j]);
     h_p1_mc->Fill(pitch_i2[last_j]);




     cout<<"induction 2 done"<<endl;
     if(ontraj_i1[last_k]!=1) continue;
     if(tpc_i1[last_k]==1) continue;



     h_azangle0_mc->Fill( TMath::ATan(x_i1[last_k]/z_i1[last_k]) );
     h_zangle0_mc->Fill( TMath::ATan(abs( (sqrt(x_i1[last_k]*x_i1[last_k] + y_i1[last_k]*y_i1[last_k]))) / (z_i1[last_k]) ) );
     h_q0_mc->Fill(dqdx_i1[last_k]);
     h_r0_mc->Fill(rr_i1[last_k]);
     h_ci0_mc->Fill(integral_i1[last_k]);
     h_wi0_mc->Fill(width_i1[last_k]);
     h_w0_mc->Fill(wire_i1[last_k]);
     h_ti0_mc->Fill(time_i1[last_k]);
     h_x0_mc->Fill(x_i1[last_k]);
     h_y0_mc->Fill(y_i1[last_k]);
     h_z0_mc->Fill(z_i1[last_k]);
     h_p0_mc->Fill(pitch_i1[last_k]);

     cout<<"induction 1 done"<<endl;
   }//end while myReader

   cout<<"MC done"<<endl;

   //Data Azimuthal Angle
   while (myReader2.Next()) {
     if(*selected2 != 0) continue; //if not stopping, move one.

     //if(*tpc2 != 0) continue;

     b++;
     cout<<"track "<<b<<endl;
     //only here if stopping 
     
     h_l_data->Fill(*length2);
     h_t0_data->Fill(*t02);
     h_sx_data->Fill(*startX2);
     h_sy_data->Fill(*startY2);
     h_sz_data->Fill(*startZ2);
     h_ex_data->Fill(*endX2);
     h_ey_data->Fill(*endY2);
     h_ez_data->Fill(*endZ2);

     cout<<"track-level done"<<endl;
     //get the last traj point on the collection plane
     int last_i2 = y2_c.GetSize()-1;
     int last_j2 = y2_i2.GetSize()-1;
     int last_k2 = y2_i1.GetSize()-1;
     //if not on thr trajectory, continue
     if(ontraj2_c[last_i2]!=1) continue;
     if(tpc2_c[last_i2]==1) continue;
     h_azangle2_data->Fill( TMath::ATan(x2_c[last_i2]/z2_c[last_i2]) );
     h_zangle2_data->Fill( TMath::ATan(abs( (sqrt(x2_c[last_i2]*x2_c[last_i2] + y2_c[last_i2]*y2_c[last_i2]))) / (z2_c[last_i2]) ) );
     h_q2_data->Fill(dqdx2_c[last_i2]);
     h_r2_data->Fill(rr2_c[last_i2]);


     h_ci2_data->Fill(integral2_c[last_i2]);
     h_wi2_data->Fill(width2_c[last_i2]);
     h_w2_data->Fill(wire2_c[last_i2]);
     h_ti2_data->Fill(time2_c[last_i2]);
     h_x2_data->Fill(x2_c[last_i2]);
     h_y2_data->Fill(y2_c[last_i2]);
     h_z2_data->Fill(z2_c[last_i2]);
     h_p2_data->Fill(pitch2_c[last_i2]);


     cout<<"collection done"<<endl;
     //if(verbose) 
     //cout << "MC angle " << TMath::ATan(x_c[last_i]/z_c[last_i]) << endl;

     //and fill all the other histograms related to traj points too
     

     if(ontraj2_i2[last_j2]!=1) continue;
     if(tpc2_i2[last_j2]==1) continue;
     h_azangle1_data->Fill( TMath::ATan(x2_i2[last_j2]/z2_i2[last_j2]) );
     h_zangle1_data->Fill( TMath::ATan(abs( (sqrt(x2_i2[last_j2]*x2_i2[last_j2] + y2_i2[last_j2]*y2_i2[last_j2]))) / (z2_i2[last_j2]) ) );
     h_q1_data->Fill(dqdx2_i2[last_j2]);
     h_r1_data->Fill(rr2_i2[last_j2]);



     h_ci1_data->Fill(integral2_i2[last_j2]);
     h_wi1_data->Fill(width2_i2[last_j2]);
     h_w1_data->Fill(wire2_i2[last_j2]);
     h_ti1_data->Fill(time2_i2[last_j2]);
     h_x1_data->Fill(x2_i2[last_j2]);
     h_y1_data->Fill(y2_i2[last_j2]);
     h_z1_data->Fill(z2_i2[last_j2]);
     h_p1_data->Fill(pitch2_i2[last_j2]);

     cout<<"induction 2 done"<<endl;


     if(ontraj2_i1[last_k2]!=1) continue;
     if(tpc2_i1[last_k2]==1) continue;
     h_azangle0_data->Fill( TMath::ATan(x2_i1[last_k2]/z2_i1[last_k2]) );
     h_zangle0_data->Fill( TMath::ATan(abs( (sqrt(x2_i1[last_k2]*x2_i1[last_k2] + y2_i1[last_k2]*y2_i1[last_k2]))) / (z2_i1[last_k2]) ) );
     h_q0_data->Fill(dqdx2_i1[last_k2]);
     h_r0_data->Fill(rr2_i1[last_k2]);


     h_ci0_data->Fill(integral2_i1[last_k2]);
     h_wi0_data->Fill(width2_i1[last_k2]);
     h_w0_data->Fill(wire2_i1[last_k2]);
     h_ti0_data->Fill(time2_i1[last_k2]);
     h_x0_data->Fill(x2_i1[last_k2]);
     h_y0_data->Fill(y2_i1[last_k2]);
     h_z0_data->Fill(z2_i1[last_k2]);
     h_p0_data->Fill(pitch2_i1[last_k2]);
     cout<<"induction 1 done"<<endl;

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

   TH1*h1AA = (TH1*)(h_ci2_mc->Clone("h1AA"));
   h1AA->Scale(1./h1AA->Integral());
   TH1*h1BB = (TH1*)(h_ci1_mc->Clone("h1BB"));
   h1BB->Scale(1./h1BB->Integral());
   TH1*h1CC = (TH1*)(h_ci0_mc->Clone("h1CC"));
   h1CC->Scale(1./h1CC->Integral());
   TH1*h1DD = (TH1*)(h_wi2_mc->Clone("h1DD"));
   h1DD->Scale(1./h1DD->Integral());
   TH1*h1EE = (TH1*)(h_wi1_mc->Clone("h1EE"));
   h1EE->Scale(1./h1EE->Integral());
   TH1*h1FF = (TH1*)(h_wi0_mc->Clone("h1FF"));
   h1FF->Scale(1./h1FF->Integral());
   TH1*h1GG = (TH1*)(h_w2_mc->Clone("h1GG"));
   h1GG->Scale(1./h1GG->Integral());
   TH1*h1HH = (TH1*)(h_w1_mc->Clone("h1HH"));
   h1HH->Scale(1./h1HH->Integral());
   TH1*h1II = (TH1*)(h_w0_mc->Clone("h1II"));
   h1II->Scale(1./h1II->Integral());
   TH1*h1JJ = (TH1*)(h_ti2_mc->Clone("h1JJ"));
   h1JJ->Scale(1./h1JJ->Integral());
   TH1*h1KK = (TH1*)(h_ti1_mc->Clone("h1KK"));
   h1KK->Scale(1./h1KK->Integral());
   TH1*h1LL = (TH1*)(h_ti0_mc->Clone("h1LL"));
   h1LL->Scale(1./h1LL->Integral());
   TH1*h1MM = (TH1*)(h_x2_mc->Clone("h1MM"));
   h1MM->Scale(1./h1MM->Integral());
   TH1*h1NN = (TH1*)(h_x1_mc->Clone("h1NN"));
   h1NN->Scale(1./h1NN->Integral());
   TH1*h1OO = (TH1*)(h_x0_mc->Clone("h1OO"));
   h1OO->Scale(1./h1OO->Integral());
   TH1*h1PP = (TH1*)(h_y2_mc->Clone("h1PP"));
   h1PP->Scale(1./h1PP->Integral());
   TH1*h1QQ = (TH1*)(h_y1_mc->Clone("h1QQ"));
   h1QQ->Scale(1./h1QQ->Integral());
   TH1*h1RR = (TH1*)(h_y0_mc->Clone("h1RR"));
   h1RR->Scale(1./h1RR->Integral());
   TH1*h1SS = (TH1*)(h_z2_mc->Clone("h1SS"));
   h1SS->Scale(1./h1SS->Integral());
   TH1*h1TT = (TH1*)(h_z1_mc->Clone("h1TT"));
   h1TT->Scale(1./h1TT->Integral());
   TH1*h1UU = (TH1*)(h_z0_mc->Clone("h1UU"));
   h1UU->Scale(1./h1UU->Integral());
   TH1*h1VV = (TH1*)(h_p2_mc->Clone("h1VV"));
   h1VV->Scale(1./h1VV->Integral());
   TH1*h1WW = (TH1*)(h_p1_mc->Clone("h1WW"));
   h1WW->Scale(1./h1WW->Integral());
   TH1*h1XX = (TH1*)(h_p0_mc->Clone("h1XX"));
   h1XX->Scale(1./h1XX->Integral());





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


   TH1*h2AA = (TH1*)(h_ci2_data->Clone("h2AA"));
   h2AA->Scale(1./h2AA->Integral());
   TH1*h2BB = (TH1*)(h_ci1_data->Clone("h2BB"));
   h2BB->Scale(1./h2BB->Integral());
   TH1*h2CC = (TH1*)(h_ci0_data->Clone("h2CC"));
   h2CC->Scale(1./h2CC->Integral());
   TH1*h2DD = (TH1*)(h_wi2_data->Clone("h2DD"));
   h2DD->Scale(1./h2DD->Integral());
   TH1*h2EE = (TH1*)(h_wi1_data->Clone("h2EE"));
   h2EE->Scale(1./h2EE->Integral());
   TH1*h2FF = (TH1*)(h_wi0_data->Clone("h2FF"));
   h2FF->Scale(1./h2FF->Integral());
   TH1*h2GG = (TH1*)(h_w2_data->Clone("h2GG"));
   h2GG->Scale(1./h2GG->Integral());
   TH1*h2HH = (TH1*)(h_w1_data->Clone("h2HH"));
   h2HH->Scale(1./h2HH->Integral());
   TH1*h2II = (TH1*)(h_w0_data->Clone("h2II"));
   h2II->Scale(1./h2II->Integral());
   TH1*h2JJ = (TH1*)(h_ti2_data->Clone("h2JJ"));
   h2JJ->Scale(1./h2JJ->Integral());
   TH1*h2KK = (TH1*)(h_ti1_data->Clone("h2KK"));
   h2KK->Scale(1./h2KK->Integral());
   TH1*h2LL = (TH1*)(h_ti0_data->Clone("h2LL"));
   h2LL->Scale(1./h2LL->Integral());
   TH1*h2MM = (TH1*)(h_x2_data->Clone("h2MM"));
   h2MM->Scale(1./h2MM->Integral());
   TH1*h2NN = (TH1*)(h_x1_data->Clone("h2NN"));
   h2NN->Scale(1./h2NN->Integral());
   TH1*h2OO = (TH1*)(h_x0_data->Clone("h2OO"));
   h2OO->Scale(1./h2OO->Integral());
   TH1*h2PP = (TH1*)(h_y2_data->Clone("h2PP"));
   h2PP->Scale(1./h2PP->Integral());
   TH1*h2QQ = (TH1*)(h_y1_data->Clone("h2QQ"));
   h2QQ->Scale(1./h2QQ->Integral());
   TH1*h2RR = (TH1*)(h_y0_data->Clone("h2RR"));
   h2RR->Scale(1./h2RR->Integral());
   TH1*h2SS = (TH1*)(h_z2_data->Clone("h2SS"));
   h2SS->Scale(1./h2SS->Integral());
   TH1*h2TT = (TH1*)(h_z1_data->Clone("h2TT"));
   h2TT->Scale(1./h2TT->Integral());
   TH1*h2UU = (TH1*)(h_z0_data->Clone("h2UU"));
   h2UU->Scale(1./h2UU->Integral());
   TH1*h2VV = (TH1*)(h_p2_data->Clone("h2VV"));
   h2VV->Scale(1./h2VV->Integral());
   TH1*h2WW = (TH1*)(h_p1_data->Clone("h2WW"));
   h2WW->Scale(1./h2WW->Integral());
   TH1*h2XX = (TH1*)(h_p0_data->Clone("h2XX"));
   h2XX->Scale(1./h2XX->Integral());





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


   TCanvas* cnvs_zz2 = new TCanvas("cnvs_zz2", "c1", 1,1,800,700);
   h1c->SetLineColor(kRed);
   h2c->SetLineColor(kBlue);
   hs_zz2->Add(h1c);
   hs_zz2->Add(h2c);
   hs_zz2->Draw("nostackHIST");


   hs_zz2->GetXaxis()->SetTitle(" Zenith Angle in radians ");
   hs_zz2->GetYaxis()->SetTitle("Relative Frequency");
   TText Tc; Tc.SetTextFont(42); Tc.SetTextAlign(21);
   Tc.DrawTextNDC(.5,.95,"Relative Frequency vs Zenith Angle (col): East Cryostat");
   auto legendc = new TLegend(0.1,0.8,0.2,0.9);
   legendc->AddEntry(h1c,"MC");
   legendc->AddEntry(h2c,"Data");
   legendc->Draw();
   cnvs_zz2->Update();

   TCanvas* cnvs_zz1 = new TCanvas("cnvs_zz1", "c1", 1,1,800,700);
   h1d->SetLineColor(kRed);
   h2d->SetLineColor(kBlue);
   hs_zz1->Add(h1d);
   hs_zz1->Add(h2d);
   hs_zz1->Draw("nostackHIST");


   hs_zz1->GetXaxis()->SetTitle(" Zenith Angle in radians ");
   hs_zz1->GetYaxis()->SetTitle("Relative Frequency");
   TText Td; Td.SetTextFont(42); Td.SetTextAlign(21);
   Td.DrawTextNDC(.5,.95,"Relative Frequency vs Zenith Angle (in1): East Cryostat");
   auto legendd = new TLegend(0.1,0.8,0.2,0.9);
   legendd->AddEntry(h1d,"MC");
   legendd->AddEntry(h2d,"Data");
   legendd->Draw();
   cnvs_zz1->Update();


   TCanvas* cnvs_zz0 = new TCanvas("cnvs_zz0", "c1", 1,1,800,700);
   h1e->SetLineColor(kRed);
   h2e->SetLineColor(kBlue);
   hs_zz0->Add(h1e);
   hs_zz0->Add(h2e);
   hs_zz0->Draw("nostackHIST");


   hs_zz0->GetXaxis()->SetTitle(" Zenith Angle in radians ");
   hs_zz0->GetYaxis()->SetTitle("Relative Frequency");
   TText Te; Te.SetTextFont(42); Te.SetTextAlign(21);
   Te.DrawTextNDC(.5,.95,"Relative Frequency vs Zenith Angle (in2): East Cryostat");
   auto legende = new TLegend(0.1,0.8,0.2,0.9);
   legende->AddEntry(h1e,"MC");
   legende->AddEntry(h2e,"Data");
   legende->Draw();
   cnvs_zz0->Update();


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
























   TCanvas* cnvs_ci2 = new TCanvas("cnvs_ci2", "c1", 1,1,800,700);
   h1AA->SetLineColor(kRed);
   h2AA->SetLineColor(kBlue);
   hs_ci2->Add(h1AA);
   hs_ci2->Add(h2AA);
   hs_ci2->Draw("nostackHIST");

   hs_ci2->GetXaxis()->SetTitle(" Charge Integral in ADC  ");
   hs_ci2->GetYaxis()->SetTitle("Relative Frequency");
   TText TAA; TAA.SetTextFont(42); TAA.SetTextAlign(21);
   TAA.DrawTextNDC(.5,.95,"Relative Frequency vs Charge Integral (col): East Cryostat");
   auto legendAA = new TLegend(0.1,0.8,0.2,0.9);
   legendAA->AddEntry(h1AA,"MC");
   legendAA->AddEntry(h2AA,"Data");
   legendAA->Draw();
   cnvs_ci2->Update();

   TCanvas* cnvs_ci1 = new TCanvas("cnvs_ci1", "c1", 1,1,800,700);
   h1BB->SetLineColor(kRed);
   h2BB->SetLineColor(kBlue);
   hs_ci1->Add(h1BB);
   hs_ci1->Add(h2BB);
   hs_ci1->Draw("nostackHIST");

   hs_ci1->GetXaxis()->SetTitle(" Charge Integral in ADC  ");
   hs_ci1->GetYaxis()->SetTitle("Relative Frequency");
   TText TBB; TBB.SetTextFont(42); TBB.SetTextAlign(21);
   TBB.DrawTextNDC(.5,.95,"Relative Frequency vs Charge Integral (in1): East Cryostat");
   auto legendBB = new TLegend(0.1,0.8,0.2,0.9);
   legendBB->AddEntry(h1BB,"MC");
   legendBB->AddEntry(h2BB,"Data");
   legendBB->Draw();
   cnvs_ci1->Update();

   TCanvas* cnvs_ci0 = new TCanvas("cnvs_ci0", "c1", 1,1,800,700);
   h1CC->SetLineColor(kRed);
   h2CC->SetLineColor(kBlue);
   hs_ci0->Add(h1CC);
   hs_ci0->Add(h2CC);
   hs_ci0->Draw("nostackHIST");

   hs_ci0->GetXaxis()->SetTitle(" Charge Integral in ADC  ");
   hs_ci0->GetYaxis()->SetTitle("Relative Frequency");
   TText TCC; TCC.SetTextFont(42); TCC.SetTextAlign(21);
   TCC.DrawTextNDC(.5,.95,"Relative Frequency vs Charge Integral (in2): East Cryostat");
   auto legendCC = new TLegend(0.1,0.8,0.2,0.9);
   legendCC->AddEntry(h1CC,"MC");
   legendCC->AddEntry(h2CC,"Data");
   legendCC->Draw();
   cnvs_ci0->Update();







   TCanvas* cnvs_wi2 = new TCanvas("cnvs_wi2", "c1", 1,1,800,700);
   h1DD->SetLineColor(kRed);
   h2DD->SetLineColor(kBlue);
   hs_wi2->Add(h1DD);
   hs_wi2->Add(h2DD);
   hs_wi2->Draw("nostackHIST");

   hs_wi2->GetXaxis()->SetTitle(" Width in ticks  ");
   hs_wi2->GetYaxis()->SetTitle("Relative Frequency");
   TText TDD; TDD.SetTextFont(42); TDD.SetTextAlign(21);
   TDD.DrawTextNDC(.5,.95,"Relative Frequency vs Width (col): East Cryostat");
   auto legendDD = new TLegend(0.1,0.8,0.2,0.9);
   legendDD->AddEntry(h1DD,"MC");
   legendDD->AddEntry(h2DD,"Data");
   legendDD->Draw();
   cnvs_wi2->Update();

   TCanvas* cnvs_wi1 = new TCanvas("cnvs_wi1", "c1", 1,1,800,700);
   h1EE->SetLineColor(kRed);
   h2EE->SetLineColor(kBlue);
   hs_wi1->Add(h1EE);
   hs_wi1->Add(h2EE);
   hs_wi1->Draw("nostackHIST");

   hs_wi1->GetXaxis()->SetTitle(" Width in ticks  ");
   hs_wi1->GetYaxis()->SetTitle("Relative Frequency");
   TText TEE; TEE.SetTextFont(42); TEE.SetTextAlign(21);
   TEE.DrawTextNDC(.5,.95,"Relative Frequency vs Width (in1): East Cryostat");
   auto legendEE = new TLegend(0.1,0.8,0.2,0.9);
   legendEE->AddEntry(h1EE,"MC");
   legendEE->AddEntry(h2EE,"Data");
   legendEE->Draw();
   cnvs_wi1->Update();

   TCanvas* cnvs_wi0 = new TCanvas("cnvs_wi0", "c1", 1,1,800,700);
   h1FF->SetLineColor(kRed);
   h2FF->SetLineColor(kBlue);
   hs_wi0->Add(h1FF);
   hs_wi0->Add(h2FF);
   hs_wi0->Draw("nostackHIST");

   hs_wi0->GetXaxis()->SetTitle(" Width in ticks  ");
   hs_wi0->GetYaxis()->SetTitle("Relative Frequency");
   TText TFF; TFF.SetTextFont(42); TFF.SetTextAlign(21);
   TFF.DrawTextNDC(.5,.95,"Relative Frequency vs Width (in2): East Cryostat");
   auto legendFF = new TLegend(0.1,0.8,0.2,0.9);
   legendFF->AddEntry(h1FF,"MC");
   legendFF->AddEntry(h2FF,"Data");
   legendFF->Draw();
   cnvs_wi0->Update();




   TCanvas* cnvs_w2 = new TCanvas("cnvs_w2", "c1", 1,1,800,700);
   h1GG->SetLineColor(kRed);
   h2GG->SetLineColor(kBlue);
   hs_w2->Add(h1GG);
   hs_w2->Add(h2GG);
   hs_w2->Draw("nostackHIST");

   hs_w2->GetXaxis()->SetTitle(" Wire Number  ");
   hs_w2->GetYaxis()->SetTitle("Relative Frequency");
   TText TGG; TGG.SetTextFont(42); TGG.SetTextAlign(21);
   TGG.DrawTextNDC(.5,.95,"Relative Frequency vs Wire (col): East Cryostat");
   auto legendGG = new TLegend(0.1,0.8,0.2,0.9);
   legendGG->AddEntry(h1GG,"MC");
   legendGG->AddEntry(h2GG,"Data");
   legendGG->Draw();
   cnvs_w2->Update();

   TCanvas* cnvs_w1 = new TCanvas("cnvs_w1", "c1", 1,1,800,700);
   h1HH->SetLineColor(kRed);
   h2HH->SetLineColor(kBlue);
   hs_w1->Add(h1HH);
   hs_w1->Add(h2HH);
   hs_w1->Draw("nostackHIST");

   hs_w1->GetXaxis()->SetTitle(" Wire Number  ");
   hs_w1->GetYaxis()->SetTitle("Relative Frequency");
   TText THH; THH.SetTextFont(42); THH.SetTextAlign(21);
   THH.DrawTextNDC(.5,.95,"Relative Frequency vs Wire (in1): East Cryostat");
   auto legendHH = new TLegend(0.1,0.8,0.2,0.9);
   legendHH->AddEntry(h1HH,"MC");
   legendHH->AddEntry(h2HH,"Data");
   legendHH->Draw();
   cnvs_w1->Update();

   TCanvas* cnvs_w0 = new TCanvas("cnvs_w0", "c1", 1,1,800,700);
   h1II->SetLineColor(kRed);
   h2II->SetLineColor(kBlue);
   hs_w0->Add(h1II);
   hs_w0->Add(h2II);
   hs_w0->Draw("nostackHIST");

   hs_w0->GetXaxis()->SetTitle(" Wire Number  ");
   hs_w0->GetYaxis()->SetTitle("Relative Frequency");
   TText TII; TII.SetTextFont(42); TII.SetTextAlign(21);
   TII.DrawTextNDC(.5,.95,"Relative Frequency vs Wire (in2): East Cryostat");
   auto legendII = new TLegend(0.1,0.8,0.2,0.9);
   legendII->AddEntry(h1II,"MC");
   legendII->AddEntry(h2II,"Data");
   legendII->Draw();
   cnvs_w0->Update();





   TCanvas* cnvs_ti2 = new TCanvas("cnvs_ti2", "c1", 1,1,800,700);
   h1JJ->SetLineColor(kRed);
   h2JJ->SetLineColor(kBlue);
   hs_ti2->Add(h1JJ);
   hs_ti2->Add(h2JJ);
   hs_ti2->Draw("nostackHIST");

   hs_ti2->GetXaxis()->SetTitle(" Time in ticks  ");
   hs_ti2->GetYaxis()->SetTitle("Relative Frequency");
   TText TJJ; TJJ.SetTextFont(42); TJJ.SetTextAlign(21);
   TJJ.DrawTextNDC(.5,.95,"Relative Frequency vs Time (col): East Cryostat");
   auto legendJJ = new TLegend(0.1,0.8,0.2,0.9);
   legendJJ->AddEntry(h1JJ,"MC");
   legendJJ->AddEntry(h2JJ,"Data");
   legendJJ->Draw();
   cnvs_ti2->Update();

   TCanvas* cnvs_ti1 = new TCanvas("cnvs_ti1", "c1", 1,1,800,700);
   h1KK->SetLineColor(kRed);
   h2KK->SetLineColor(kBlue);
   hs_ti1->Add(h1KK);
   hs_ti1->Add(h2KK);
   hs_ti1->Draw("nostackHIST");

   hs_ti1->GetXaxis()->SetTitle(" Time in ticks  ");
   hs_ti1->GetYaxis()->SetTitle("Relative Frequency");
   TText TKK; TKK.SetTextFont(42); TKK.SetTextAlign(21);
   TKK.DrawTextNDC(.5,.95,"Relative Frequency vs Time (in1): East Cryostat");
   auto legendKK = new TLegend(0.1,0.8,0.2,0.9);
   legendKK->AddEntry(h1KK,"MC");
   legendKK->AddEntry(h2KK,"Data");
   legendKK->Draw();
   cnvs_ti1->Update();

   TCanvas* cnvs_ti0 = new TCanvas("cnvs_ti0", "c1", 1,1,800,700);
   h1LL->SetLineColor(kRed);
   h2LL->SetLineColor(kBlue);
   hs_ti0->Add(h1LL);
   hs_ti0->Add(h2LL);
   hs_ti0->Draw("nostackHIST");

   hs_ti0->GetXaxis()->SetTitle(" Time in ticks  ");
   hs_ti0->GetYaxis()->SetTitle("Relative Frequency");
   TText TLL; TLL.SetTextFont(42); TLL.SetTextAlign(21);
   TLL.DrawTextNDC(.5,.95,"Relative Frequency vs Time (in2): East Cryostat");
   auto legendLL = new TLegend(0.1,0.8,0.2,0.9);
   legendLL->AddEntry(h1LL,"MC");
   legendLL->AddEntry(h2LL,"Data");
   legendLL->Draw();
   cnvs_ti0->Update();


   TCanvas* cnvs_x2 = new TCanvas("cnvs_x2", "c1", 1,1,800,700);
   h1MM->SetLineColor(kRed);
   h2MM->SetLineColor(kBlue);
   hs_x2->Add(h1MM);
   hs_x2->Add(h2MM);
   hs_x2->Draw("nostackHIST");

   hs_x2->GetXaxis()->SetTitle(" Distance (X) in cm  ");
   hs_x2->GetYaxis()->SetTitle("Relative Frequency");
   TText TMM; TMM.SetTextFont(42); TMM.SetTextAlign(21);
   TMM.DrawTextNDC(.5,.95,"Relative Frequency vs Distance (X) (col): East Cryostat");
   auto legendMM = new TLegend(0.1,0.8,0.2,0.9);
   legendMM->AddEntry(h1MM,"MC");
   legendMM->AddEntry(h2MM,"Data");
   legendMM->Draw();
   cnvs_x2->Update();

   TCanvas* cnvs_x1 = new TCanvas("cnvs_x1", "c1", 1,1,800,700);
   h1NN->SetLineColor(kRed);
   h2NN->SetLineColor(kBlue);
   hs_x1->Add(h1NN);
   hs_x1->Add(h2NN);
   hs_x1->Draw("nostackHIST");

   hs_x1->GetXaxis()->SetTitle(" Distance (X) in cm  ");
   hs_x1->GetYaxis()->SetTitle("Relative Frequency");
   TText TNN; TNN.SetTextFont(42); TNN.SetTextAlign(21);
   TNN.DrawTextNDC(.5,.95,"Relative Frequency vs Distance (X) (in1): East Cryostat");
   auto legendNN = new TLegend(0.1,0.8,0.2,0.9);
   legendNN->AddEntry(h1NN,"MC");
   legendNN->AddEntry(h2NN,"Data");
   legendNN->Draw();
   cnvs_x1->Update();

   TCanvas* cnvs_x0 = new TCanvas("cnvs_x0", "c1", 1,1,800,700);
   h1OO->SetLineColor(kRed);
   h2OO->SetLineColor(kBlue);
   hs_x0->Add(h1OO);
   hs_x0->Add(h2OO);
   hs_x0->Draw("nostackHIST");

   hs_x0->GetXaxis()->SetTitle(" Distance (X) in cm  ");
   hs_x0->GetYaxis()->SetTitle("Relative Frequency");
   TText TOO; TOO.SetTextFont(42); TOO.SetTextAlign(21);
   TOO.DrawTextNDC(.5,.95,"Relative Frequency vs Distance (X) (in2): East Cryostat");
   auto legendOO = new TLegend(0.1,0.8,0.2,0.9);
   legendOO->AddEntry(h1OO,"MC");
   legendOO->AddEntry(h2OO,"Data");
   legendOO->Draw();
   cnvs_x0->Update();






   TCanvas* cnvs_y2 = new TCanvas("cnvs_y2", "c1", 1,1,800,700);
   h1PP->SetLineColor(kRed);
   h2PP->SetLineColor(kBlue);
   hs_y2->Add(h1PP);
   hs_y2->Add(h2PP);
   hs_y2->Draw("nostackHIST");

   hs_y2->GetXaxis()->SetTitle(" Distance (Y) in cm  ");
   hs_y2->GetYaxis()->SetTitle("Relative Frequency");
   TText TPP; TPP.SetTextFont(42); TPP.SetTextAlign(21);
   TPP.DrawTextNDC(.5,.95,"Relative Frequency vs Distance (Y) (col): East Cryostat");
   auto legendPP = new TLegend(0.1,0.8,0.2,0.9);
   legendPP->AddEntry(h1PP,"MC");
   legendPP->AddEntry(h2PP,"Data");
   legendPP->Draw();
   cnvs_y2->Update();

   TCanvas* cnvs_y1 = new TCanvas("cnvs_y1", "c1", 1,1,800,700);
   h1QQ->SetLineColor(kRed);
   h2QQ->SetLineColor(kBlue);
   hs_y1->Add(h1QQ);
   hs_y1->Add(h2QQ);
   hs_y1->Draw("nostackHIST");

   hs_y1->GetXaxis()->SetTitle(" Distance (Y) in cm  ");
   hs_y1->GetYaxis()->SetTitle("Relative Frequency");
   TText TQQ; TQQ.SetTextFont(42); TQQ.SetTextAlign(21);
   TQQ.DrawTextNDC(.5,.95,"Relative Frequency vs Distance (Y) (in1): East Cryostat");
   auto legendQQ = new TLegend(0.1,0.8,0.2,0.9);
   legendQQ->AddEntry(h1QQ,"MC");
   legendQQ->AddEntry(h2QQ,"Data");
   legendQQ->Draw();
   cnvs_y1->Update();

   TCanvas* cnvs_y0 = new TCanvas("cnvs_y0", "c1", 1,1,800,700);
   h1RR->SetLineColor(kRed);
   h2RR->SetLineColor(kBlue);
   hs_y0->Add(h1RR);
   hs_y0->Add(h2RR);
   hs_y0->Draw("nostackHIST");

   hs_y0->GetXaxis()->SetTitle(" Distance (Y) in cm  ");
   hs_y0->GetYaxis()->SetTitle("Relative Frequency");
   TText TRR; TRR.SetTextFont(42); TRR.SetTextAlign(21);
   TRR.DrawTextNDC(.5,.95,"Relative Frequency vs Distance (Y) (in2): East Cryostat");
   auto legendRR = new TLegend(0.1,0.8,0.2,0.9);
   legendRR->AddEntry(h1RR,"MC");
   legendRR->AddEntry(h2RR,"Data");
   legendRR->Draw();
   cnvs_y0->Update();







   TCanvas* cnvs_z2 = new TCanvas("cnvs_z2", "c1", 1,1,800,700);
   h1SS->SetLineColor(kRed);
   h2SS->SetLineColor(kBlue);
   hs_z2->Add(h1SS);
   hs_z2->Add(h2SS);
   hs_z2->Draw("nostackHIST");

   hs_z2->GetXaxis()->SetTitle(" Distance (Z) in cm  ");
   hs_z2->GetYaxis()->SetTitle("Relative Frequency");
   TText TSS; TSS.SetTextFont(42); TSS.SetTextAlign(21);
   TSS.DrawTextNDC(.5,.95,"Relative Frequency vs Distance (Z) (col): East Cryostat");
   auto legendSS = new TLegend(0.1,0.8,0.2,0.9);
   legendSS->AddEntry(h1SS,"MC");
   legendSS->AddEntry(h2SS,"Data");
   legendSS->Draw();
   cnvs_z2->Update();

   TCanvas* cnvs_z1 = new TCanvas("cnvs_z1", "c1", 1,1,800,700);
   h1TT->SetLineColor(kRed);
   h2TT->SetLineColor(kBlue);
   hs_z1->Add(h1TT);
   hs_z1->Add(h2TT);
   hs_z1->Draw("nostackHIST");

   hs_z1->GetXaxis()->SetTitle(" Distance (Z) in cm  ");
   hs_z1->GetYaxis()->SetTitle("Relative Frequency");
   TText TTT; TTT.SetTextFont(42); TTT.SetTextAlign(21);
   TTT.DrawTextNDC(.5,.95,"Relative Frequency vs Distance (Z) (in1): East Cryostat");
   auto legendTT = new TLegend(0.1,0.8,0.2,0.9);
   legendTT->AddEntry(h1TT,"MC");
   legendTT->AddEntry(h2TT,"Data");
   legendTT->Draw();
   cnvs_z1->Update();

   TCanvas* cnvs_z0 = new TCanvas("cnvs_z0", "c1", 1,1,800,700);
   h1UU->SetLineColor(kRed);
   h2UU->SetLineColor(kBlue);
   hs_z0->Add(h1UU);
   hs_z0->Add(h2UU);
   hs_z0->Draw("nostackHIST");

   hs_z0->GetXaxis()->SetTitle(" Distance (Z) in cm  ");
   hs_z0->GetYaxis()->SetTitle("Relative Frequency");
   TText TUU; TUU.SetTextFont(42); TUU.SetTextAlign(21);
   TUU.DrawTextNDC(.5,.95,"Relative Frequency vs Distance (Z) (in2): East Cryostat");
   auto legendUU = new TLegend(0.1,0.8,0.2,0.9);
   legendUU->AddEntry(h1UU,"MC");
   legendUU->AddEntry(h2UU,"Data");
   legendUU->Draw();
   cnvs_z0->Update();





   TCanvas* cnvs_p2 = new TCanvas("cnvs_p2", "c1", 1,1,800,700);
   h1VV->SetLineColor(kRed);
   h2VV->SetLineColor(kBlue);
   hs_p2->Add(h1VV);
   hs_p2->Add(h2VV);
   hs_p2->Draw("nostackHIST");

   hs_p2->GetXaxis()->SetTitle(" Pitch in cm  ");
   hs_p2->GetYaxis()->SetTitle("Relative Frequency");
   TText TVV; TVV.SetTextFont(42); TVV.SetTextAlign(21);
   TVV.DrawTextNDC(.5,.95,"Relative Frequency vs Pitch (col): East Cryostat");
   auto legendVV = new TLegend(0.1,0.8,0.2,0.9);
   legendVV->AddEntry(h1VV,"MC");
   legendVV->AddEntry(h2VV,"Data");
   legendVV->Draw();
   cnvs_p2->Update();

   TCanvas* cnvs_p1 = new TCanvas("cnvs_p1", "c1", 1,1,800,700);
   h1WW->SetLineColor(kRed);
   h2WW->SetLineColor(kBlue);
   hs_p1->Add(h1WW);
   hs_p1->Add(h2WW);
   hs_p1->Draw("nostackHIST");

   hs_p1->GetXaxis()->SetTitle(" Pitch in cm  ");
   hs_p1->GetYaxis()->SetTitle("Relative Frequency");
   TText TWW; TWW.SetTextFont(42); TWW.SetTextAlign(21);
   TWW.DrawTextNDC(.5,.95,"Relative Frequency vs Pitch (in1): East Cryostat");
   auto legendWW = new TLegend(0.1,0.8,0.2,0.9);
   legendWW->AddEntry(h1WW,"MC");
   legendWW->AddEntry(h2WW,"Data");
   legendWW->Draw();
   cnvs_p1->Update();

   TCanvas* cnvs_p0 = new TCanvas("cnvs_p0", "c1", 1,1,800,700);
   h1XX->SetLineColor(kRed);
   h2XX->SetLineColor(kBlue);
   hs_p0->Add(h1XX);
   hs_p0->Add(h2XX);
   hs_p0->Draw("nostackHIST");

   hs_p0->GetXaxis()->SetTitle(" Pitch in cm  ");
   hs_p0->GetYaxis()->SetTitle("Relative Frequency");
   TText TXX; TXX.SetTextFont(42); TXX.SetTextAlign(21);
   TXX.DrawTextNDC(.5,.95,"Relative Frequency vs Pitch (in2): East Cryostat");
   auto legendXX = new TLegend(0.1,0.8,0.2,0.9);
   legendXX->AddEntry(h1XX,"MC");
   legendXX->AddEntry(h2XX,"Data");
   legendXX->Draw();
   cnvs_p0->Update();




   cout<<"plots done"<<endl;


   std::cout << "Number of files in our MC list is " << my_files->GetNFiles() << std::endl;
   std::cout << "Number of files in our data list is " << my_files2->GetNFiles() << std::endl;

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

