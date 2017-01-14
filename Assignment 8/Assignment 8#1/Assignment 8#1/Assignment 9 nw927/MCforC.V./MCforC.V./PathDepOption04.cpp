//
//  PathDepOption03.cpp
//  MCforGreeks
//
//  Created by 汪念怡 on 4/7/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include "PathDepOption04.h"
#include <cmath>

void Rescale(SamplePath& S, double x){
    int m=S.size();
    for (int j=0;j<m;j++) S[j]=S[j]*x;
}

double PathDepOption::PriceByMC(BSModel Model, long N,double epsilon){
    double H=0.0, Hsq=0.0, Heps_plus=0.0;
    SamplePath S(m);
    for (long i=0;i<N;i++){
        Model.GenerateSamplePath(T, m, S);
        H=(i*H+Payoff(S))/(1.0+i);
        Hsq=(i*Hsq+pow(Payoff(S),2.0))/(1+i);
        Rescale(S,1+epsilon);
        Heps_plus=(i*Heps_plus+Payoff(S))/(1.0+i);

    }
    Price=exp(-Model.r*T)*H;
    PricingError=exp(-Model.r*T)*sqrt(Hsq-H*H)/sqrt(N-1);
    Delta=exp(-Model.r*T)*(Heps_plus-H)/(Model.S0*epsilon);
    
    return Price;
}

double PathDepOption::PriceByVarRedMC(BSModel Model, long N, PathDepOption& CVOption, double epsilon){
    DifferenceOfOptions VarRedOpt(T,m,this,&CVOption);
    
    Price=VarRedOpt.PriceByMC(Model,N,epsilon)+CVOption.PriceByBSFormula(Model);
//    Delta=VarRedOpt.Delta;
    Delta=VarRedOpt.Delta+CVOption.Delta;
    PricingError=VarRedOpt.PricingError;
    
    return Price;
}

double ArthmAsianCall::Payoff(SamplePath &S){
    double Ave=0.0;
    for (int k=0;k<m;k++) Ave=(k*Ave+S[k])/(k+1.0);
    if (Ave<K) return 0.0;
    return Ave-K;
}

// PathDepOption -> CVOption, DifferenceofOptions -> VarRedOpt;
// PathDepOption:differenceofoptions & Arthasiancall & GmtrAsianCall
// PathDepOption:pricebyMC & pricebyVarRedMC & PricebyBS
// CVOption is geometric Asian call price = Control Variate;













