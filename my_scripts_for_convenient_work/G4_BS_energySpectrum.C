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

void G4_BS_energySpectrum()
{   
   gROOT->Reset(); 
      
//__ 

   char fileName1[80];
   FILE *myFile1;
   
  // ------- filename :
   do
   {
	printf("----->>>  fileName (from G4 output) for BS ions :    ");
        scanf("%s", &fileName1);
   	myFile1 = fopen(fileName1, "rt");
   	if (myFile1 == NULL)
   	 	printf("Error opening file %s , try again\n", fileName1);
   	else
   		break;
   }
   while (true);
   //---
   
   
   
   float   all_ions1;  // =  100000000 ;  //  
   
   printf("Enter a number of primary ions:     ");
   scanf("%f", &all_ions1);
   
   printf("all_ions1  = %.0f\n", all_ions1);
   
  
   
   TCanvas *c1 = new TCanvas("G4_EnergySpectrum_of_BS_ions","Read Data",0,0,1000,1000); 
   
   c1->SetFillColor(10); 
   c1->SetGrid();
   //c1->SetLogy();

   double Xmax = 6.0;         // energy of ions, keV
   
   int bin = Xmax*500; //  points per 1 keV 
   
   gStyle->SetOptStat(kFALSE);
    	  		
   TH1F *h1 = new TH1F("h1","Incident He ions, E_{start}=6 keV, #theta=0#circ,  Target = W 98.8A  + C substrate", bin, 0, Xmax);   
   				// #theta=0#circ-50#circ, #phi=0#circ-0#circ,  		
    		
 //--------------------
   
 
   float  Eend, X, Y, Z, vx, vy, vz ;    
   // read from the G4 output file 
   while ( !feof(myFile1)  ) 
   {     
        fscanf(myFile1, "%f %f %f %f %f %f %f", &Eend, &X, &Y, &Z, &vx, &vy, &vz);   			 
	
	Eend = Eend * 1000;    // in keV
	h1->Fill(Eend);  
		
   }

   fclose(myFile1);
   
 
  
    
  

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
   
   
   h1->SetMarkerStyle(kFullCircle); 
   h1->SetMarkerColor(kBlue+2);
   h1->SetMarkerSize(1);
   
   h1->SetLineColor(kBlue-5);
   h1->SetLineWidth(2);
 
   h1->GetXaxis()->SetRangeUser(0, Xmax); //############   0.0   //h1->GetXaxis()->SetRangeUser(30.0, 90.0); //############   0.0
   
   h1->GetYaxis()->SetRangeUser(0, 1.2*(h1->GetBinContent(h1->GetMaximumBin())));   // 1.1 * max
 
   
   
   //TLegend legend = new TLegend(0.1,0.7,0.48,0.9); //x1,y1,x2,y2 are the coordinates of the Legend in the current pad (in normalised coordinates by default)
   //TLegend *legend = new TLegend(0.4, 0.7, 0.8,0.9);
   TLegend *legend = new TLegend(0.8,0.85,0.9,0.9);
   legend->AddEntry(h1,"G4","lp");
   legend->Draw();
   //c1->Update();
   
   
   h1->Draw();             
   //h2->Draw("same");
   

   legend->Draw();
   
   c1->Update();
   
   c1->Modified();
   
  
}
