#define analysis_cxx
#include "analysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void analysis::Loop()
{
//   In a ROOT session, you can do:
//      root> .L analysis.C
//      root> analysis t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch


//TFile *file= new TFile("Histogramas.root", "RECREATE" );
//  TFile f("Histogramas.root","RECREATE");

  if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      
      /////
      
      if (!(Q2>1&&W>2&&Nu/10.6<0.85)) continue;

      int npip;
      npip= 0;
      int ind_pip;
      ind_pip = -1;
      //x/ at least one pi+; pid 211 ///
      for (int k=0; k<npart;k++ ){
        
	if (pid[k]==211){
	  npip++;
	  ind_pip = k;
	}
	        
      }
      if (npip == 1){
	Float_t th=acos(Pz[ind_pip]/P[ind_pip])*TMath::RadToDeg() ;
        hpth->Fill(P[ind_pip],th );

        hMx->Fill(sqrt(Mx2[ind_pip] ));
	//	TH1D *h=GetHisto( h , HMx[14][12] , P[ind_pip] , th);
	//h->Fill(sqrt(Mx2[ind_pip] ));
        /////////////////////////////////// 	

	TH1D *h;
       	for(int kk=0;kk<14;kk++){
	  //std::cout << " kk*0.5=  " << kk*0.5 << " P=   " << P[ind_pip] <<  "  kk*0.5+0.5=  " << kk*0.5+0.5 <<"\n" ;
	  if( (kk*0.5)<P[ind_pip] && P[ind_pip]<=(kk*0.5+0.5) ){
	    //std::cout << "hola2 \n";
	    for(int jj=0;jj<12;jj++){
	      if((jj*5)<th && th <=(jj*5+5) ){
		//h=HMx[kk][j];
		std::cout << " funciona "<< " kk= " << kk << " jj= " << jj ;
		HMx[kk][jj]->Fill(sqrt(Mx2[ind_pip] ));
	      }
	    }
	  }
	}
	//h->Fill(sqrt(Mx2[ind_pip] ));
	
	////////////////////////
	
     } 
      // if (Cut(ientry) < 0) continue;
   }
   
   std::unique_ptr<TFile> myFile( TFile::Open("Histogramas.root", "RECREATE") );
   hMx->Write();
   hpth->Write();
   for(int k=0;k<14;k++){
     for(int j=0;j<12;j++){
     HMx[k][j]->Write();  
     }
   }   
}




