#include "../include/TriggerLateStudy.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

bool TriggerLateStudy::HLT()
{
    bool HLTFlag = false;
    for(int i=0; i!=HLT_info_n; i++){
        if((*HLT_info_chain)[i] == "HLT_noalg_L12MU4"){
            if((*HLT_info_isPassed)[i] == 1){
                HLTFlag = true;
            }
        }
    }
    return HLTFlag;
}
bool TriggerLateStudy::Match()
{
    return true;
}

