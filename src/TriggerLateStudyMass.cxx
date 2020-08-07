#include "../include/TriggerLateStudy.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>
#include "map"

using namespace std;

void TriggerLateStudy::Mass()
{
    int candidate = RoI_pt.size();
    for(int i=0;i!=candidate;i++){
        for(int j=i+1;j!=candidate;j++){
            if(RoI_pt.at(i)<=11 && RoI_pt.at(j)<=11){
                float eta_cal = cosh(RoI_eta.at(i) - RoI_eta.at(j));
                float phi_cal = cos(RoI_phi.at(i) - RoI_phi.at(j));
                float mass = 2*RoI_pt.at(i)*RoI_pt.at(j)*(eta_cal - phi_cal);
                h_mass->Fill(sqrt(mass));
                h_L1pt->Fill(RoI_pt.at(i), RoI_pt.at(j));
                h_late->Fill(3);
                if(sqrt(mass)>=3.5 && sqrt(mass)<=7.5){
                    h_late->Fill(4);
                }
            }
        }
    }
}
