//
//  main.cpp
//  MCforGreeks
//
//  Created by 汪念怡 on 4/7/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include <iostream>
#include "PathDepOption03.h"
using namespace std;

int main() {
    double S0=100.0, r=0.03, sigma=0.2;
    double T=1.0/12.0, K=100.0;
    int m=30;
    double epsilon=0.001;
    long N=30000;  //repeate times
    
    BSModel Model(S0,r,sigma);
    ArthmAsianCall Option(T,K,m);
    
    Option.PriceByMC(Model, N, epsilon);
    cout<<"Asian call price = "<<Option.Price<<endl;
    cout<<"Priceing Error = "<<Option.PricingError<<endl;
    cout<<"Delta = "<<Option.delta<<endl;
    cout<<"Gamma = "<<Option.gamma<<endl;
    
    return 0;
}
