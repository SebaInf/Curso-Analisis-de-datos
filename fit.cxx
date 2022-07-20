{

  float p0;
  float p1;
  float p2;
  float mean[14][12];
  float sigma[14][12];
  
  int temp1=0;
  int temp2=0;
  int exfit[14][12];
  int count=0;
  
  TH3D *MnMean;
  TH3D *MnSigma;
  TH2D *ExFit;
  
  TFile f("Histogramas.root","READ");
  TH2D *hpth = (TH2D*)f.Get("hpth");
  TH1D *hMx  = (TH1D*)f.Get("hMx");
  TH1D *HMx[14][12];
  for(int k=0; k<14;k++){
    for(int j=0; j<12;j++){
      if (k>9){

	HMx[k][j]=(TH1D*)f.Get(TString("hMx")+(100*k+j));
	
      }
      if (k<10){

	HMx[k][j] = (TH1D*)f.Get(TString("hMx0")+(100*k+j));
      }
      // HMx[k][j]=(TH1D*)f.Get("hMx");
    }
  }

  
 
  TF1 * f1 = new TF1("f1","gaus(0)");
  TF1 * f2 = new TF1("f1","gaus(0)+pol2(3)");
  

  hMx->Fit(f1,"N","",0.85,1.15);
  //HMx[0][0]->Fit(f1,"N","",0.85,1.15);
  
  p0 = f1->GetParameter(0);
  p1 = f1->GetParameter(1);
  p2 = f1->GetParameter(2);
  
  f2->SetParameters(p0,p1,p2,0,0,0);
  
  hMx->Fit(f2,"","",0.85,1.15);
  //HMx[0][0]->Fit(f2,"","",0.85,1.15);
  
  for(int k=0;k<14;k++){
    for(int j=0;j<12;j++){
      temp1=0;
      temp2=0;
      exfit[k][j]=0;
      for(int l=43;l<59;l++){
	temp1=HMx[k][j]->GetBinContent(l);
	temp2=temp2+temp1;
      }
      
      if (temp2>40){
	f1->SetParameters(0,0,0,0,0,0);
	f2->SetParameters(0,0,0,0,0,0);
	
	HMx[k][j]->Fit(f1,"N","",0.85,1.15);

	std::cout <<temp2;
	
	p0 = f1->GetParameter(0);
	p1 = f1->GetParameter(1);
	p2 = f1->GetParameter(2);

	f2->SetParameters(p0,p1,p2,0,0,0);

	HMx[k][j]->Fit(f2,"","",0.85,1.15);

	HMx[k][j]->SetXTitle("Missing Mass");
	HMx[k][j]->SetYTitle("Numero Eventos");

	mean[k][j]  = f2->GetParameter(1);
	sigma[k][j] = f2->GetParameter(2);
       
	exfit[k][j]=1;
	count=count+1;

      }
    }
  }
  
  for(int k=14;k<14;k++){
    for(int j=0;j<12;j++){
      std::cout << exfit[k][j]<< "\n";
    }
  }
  
  std::cout << "Tenemos " << count<< " histogramas \n ";

  MnMean  = new TH3D("MnMean" ,"Media de la masa del neutron",200,0,7,200,0,60, 200,0,2 );
  MnSigma = new TH3D("MnSigma","Sigma de la masa del neutron",200,0,7,200,0,60, 200,0,2 );
  ExFit   = new TH2D("ExFit","Existencia de estadistica suficiente",200,0,7,200,0,60 );
  ExFit->SetMarkerStyle(21);
  ExFit->SetMarkerSize(1);
  ExFit->SetStats(kFALSE);
  ExFit->SetXTitle("Momemto[GeV]");
  ExFit->SetYTitle("Angulo");
  
  for(int k=0;k<14;k++){
    for(int j=0;j<12;j++){
      if(exfit[k][j]==1){
	
	ExFit->Fill(k*0.5+0.25,j*5+2.5);
	
	MnMean->Fill(k*0.5+0.25,j*5+2.5,mean[k][j]);
	MnMean->SetMarkerStyle(21);
	MnMean->SetMarkerSize(1);
	MnMean->SetXTitle("Momemto[GeV]");
	MnMean->SetYTitle("Angulo");
	MnMean->SetZTitle("Mean");
	
	MnSigma->Fill(k*0.5+0.25,j*5+2.5,sigma[k][j]);
	MnSigma->SetMarkerStyle(21);
	MnSigma->SetMarkerSize(1);
	MnSigma->SetXTitle("Momemto[GeV]");
	MnSigma->SetYTitle("Angulo");
	MnSigma->SetZTitle("Sigma");
      }
    }
  }

  std::unique_ptr<TFile> myFile( TFile::Open("FittedHist.root", "RECREATE") );
  ExFit->Write();
  hMx->Write();
  MnMean->Write();
  MnSigma->Write();
  for(int k=0;k<14;k++){
    for(int j=0;j<12;j++){
      if(exfit[k][j]==1){
	HMx[k][j]->Write();
      }
    }
  }

  
}
