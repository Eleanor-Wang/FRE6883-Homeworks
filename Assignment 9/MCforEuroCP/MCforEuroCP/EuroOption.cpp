//
//  EuroOption.cpp
//  MCforEuroCP
//
//  Created by 汪念怡 on 4/7/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include "EuroOption.h"
#include <cmath>
using namespace std;

double PathDepOption::PriceByMC(BSModel Model, long N){
    double H=0.0;
    SamplePath S(m);
    for (long i=0;i<N;i++){
        Model.GenerateSamplePath(T, m, S);
        H=(i*H+Payoff(S))/(i+1.0);
    }
    return exp(-Model.r*T)*H;
//    return *(S.end()-1);
}

double Eurocall::Payoff(SamplePath &S){
    if (*(S.end()-1)<K) return 0.0;
    return *(S.end()-1)-K;
}

double Europut::Payoff(SamplePath &S){
    if (*(S.end()-1)<K) return K-*(S.end()-1);
    return 0.0;
}