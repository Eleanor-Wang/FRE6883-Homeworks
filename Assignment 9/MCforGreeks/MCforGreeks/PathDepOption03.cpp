//
//  PathDepOption03.cpp
//  MCforGreeks
//
//  Created by 汪念怡 on 4/7/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include "PathDepOption03.h"
#include <cmath>

void Rescale(SamplePath& S, double x){
    int m=S.size();
    for (int j=0;j<m;j++) S[j]=S[j]*x;
}

double PathDepOption::PriceByMC(BSModel Model, long N, double epsilon){
    double H=0.0, Hsq=0.0, Heps_minus=0.0, Heps_plus=0.0;
    SamplePath S(m);
    for (long i=0;i<N;i++){
        Model.GenerateSamplePath(T, m, S);
        H=(i*H+Payoff(S))/(1.0+i);
        Hsq=(i*Hsq+pow(Payoff(S),2.0))/(1+i);
        Rescale(S,1+epsilon);
        Heps_plus=(i*Heps_plus+Payoff(S))/(1.0+i);
        Rescale(S,(1-epsilon)/(1+epsilon));
        Heps_minus=(i*Heps_minus+Payoff(S))/(1.0+i);
    }
    Price=exp(-Model.r*T)*H;
    PricingError=exp(-Model.r*T)*sqrt(Hsq-H*H)/sqrt(N-1);
    delta=exp(-Model.r*T)*(Heps_plus-H)/(Model.S0*epsilon);
    gamma=exp(-Model.r*T)*(Heps_plus+Heps_minus-2*H)/pow((Model.S0*epsilon),2);
    
    return Price;
}

double ArthmAsianCall::Payoff(SamplePath &S){
    double Ave=0.0;
    for (int k=0;k<m;k++) Ave=(k*Ave+S[k])/(k+1.0);
    if (Ave<K) return 0.0;
    return Ave-K;
}

