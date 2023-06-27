 //----------------------------
#include <stdio.h>
#include <TMath.h>
#include <TRandom.h>
#include "TRandom3.h"
#include "TH1.h"
#include "TF1.h"
#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"
#include "TRandom2.h"
#include "TError.h"
#include <iostream>
#include <string.h>
#include <math.h>

void MD_EnergySpectrum_He_in_W()
{   
   gROOT->Reset(); 
   
   
//__ 

   char fileName1[80];
   FILE *myFile1;
   
  // ------- the first file :
   do
   {
	printf("----->>>  fileName1 (from MD) for   70 keV H ions in Cu  :    ");
        scanf("%s", &fileName1);
   	myFile1 = fopen(fileName1, "rt");
   	if (myFile1 == NULL)
   	 	printf("Error opening file %s , try again\n", fileName1);
   	else
   		break;
   }
   while (true);
   //---
   
   
  
   
   TCanvas *c1 = new TCanvas("MD_EnergySpectrum_BSions_He_in_W","Read Data",0,0,1000,1000); 
   
   c1->SetFillColor(10); 
   c1->SetGrid();
   //c1->SetLogy();

   double Xmax = 6.0;         // energy of ions, keV
   
   int bin = Xmax*100; //  
   
   gStyle->SetOptStat(kFALSE);
    	  		
   TH1F *h1 = new TH1F("h1","Incident He ions, E_{start}=6 keV,  Target = W 98.8A  on C substrate", bin, 0, Xmax);   
   				// #theta=0#circ-50#circ, #phi=0#circ-0#circ,  		
    		
 //--------------------
   
 
   float  N, sx, sy, sz,   Eend, RangeTotal,   vx, vy, vz,  FD, FDnuc, FDelec ;    
   // read from the MD  file for plotting a Histogram  
   while ( !feof(myFile1)  ) 
   {     
        fscanf(myFile1, "%f %f %f %f %f %f %f %f %f %f %f %f", &N, &sx, &sy, &sz, &Eend, &RangeTotal,  &vx, &vy, &vz,  &FD, &FDnuc, &FDelec);   			 
	
	Eend = Eend/1000;    // in keV
	h1->Fill(Eend);  
		
   }

  fclose(myFile1);
   
 
 
  
   float   all_ions1 =  15597432 ;  
   printf("all_ions1 =  15597432   Is it a correct value ? \n");
    
  

   h1->GetXaxis()->SetTitle("Energy (keV) of all backscattered ions");  
   h1->GetXaxis()->SetTitleOffset(1); 
    
   h1->GetYaxis()->SetTitle("Relative number (per 1 projectile)");   
   h1->GetYaxis()->SetTitleOffset(1); 


   if (all_ions1 ==0) 
   {
     printf("number of projectiles is  0 \n");
     exit(-1);
   }
   
   h1->Scale(1.0/all_ions1);


   h1->SetLineColor(kBlue);
  
   h1->SetLineWidth(4);
   
   
   h1->SetMarkerStyle(kFullSquare); 
   h1->SetMarkerColor(kCyan+2);
   h1->SetMarkerSize(1);
   
   h1->SetLineColor(kGreen-5);
   h1->SetLineWidth(1);
 
   h1->GetXaxis()->SetRangeUser(0, Xmax); //############   0.0   //h1->GetXaxis()->SetRangeUser(30.0, 90.0); //############   0.0
   
   h1->GetYaxis()->SetRangeUser(0, 1.2*(h1->GetBinContent(h1->GetMaximumBin())));   // 1.1 * max
 
   
   
   TLegend *legend = new TLegend(0.8,0.85,0.9,0.9);
   legend->AddEntry(h1,"MD","lp");
   legend->Draw();
   //c1->Update();
   
   
  
  
   h1->Draw();             
   //h2->Draw("same");
   

   legend->Draw();
   
   c1->Update();
   
   c1->Modified();
   
  
}
