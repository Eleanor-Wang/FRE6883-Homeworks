//
//  BSModel01.cpp
//  Assignment9 #1
//
//  Created by 汪念怡 on 4/2/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include "BSModel01.h"
#include <cmath>

const double pi=4.0*atan(1.0);
double Gauss(){
    double U1=(rand()+1)/(RAND_MAX+1.0);
    double U2=(rand()+1)/(RAND_MAX+1.0);
    return sqrt(-2.0*log(U1))*cos(2.0*pi*U2);
}

void BSModel::GenerateSamplePath(double T, int m, SamplePath& S){
    double St=S0;
    for (int k=0;k<m;k++){
        S[k]=St*exp((r-sigma*sigma*0.5)*(T/m)+sigma*sqrt(T/m)*Gauss());
        St=S[k];
    }
}