//
//  main.cpp
//  MCforGreeks
//
//  Created by 汪念怡 on 4/7/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include <iostream>
#include "PathDepOption04.h"
#include "GmtrAsianCall.h"

using namespace std;

int main() {
    double S0=100.0, r=0.03, sigma=0.2;
    double T=1.0/12.0, K=100.0;
    int m=30;
    double epsilon=0.001;
    long N=30000;  //repeate times
    
    BSModel Model(S0,r,sigma);
    ArthmAsianCall Option(T,K,m);
    GmtrAsianCall CVOption(T,K,m);
    
    Option.PriceByVarRedMC(Model, N, CVOption,epsilon);
    cout<<"revised Arithmetic Asian Call price = "<<Option.Price<<endl<<"Pricing Error = "<<Option.PricingError<<endl<<"Delta = "<<Option.Delta<<endl<<endl;
    Option.PriceByMC(Model, N,epsilon);
    
    cout<<"direct Arithmetic Asian Call price = "<<Option.Price<<endl<<"Pricing Error = "<<Option.PricingError<<endl<<"Delta = "<<Option.Delta<<endl<<endl;
    
    return 0;
}
