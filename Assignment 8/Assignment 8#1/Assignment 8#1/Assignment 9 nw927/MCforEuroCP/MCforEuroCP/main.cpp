//
//  main.cpp
//  MCforEuroCP
//
//  Created by 汪念怡 on 4/7/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include <iostream>
#include "EuroOption.h"
using namespace std;

int main() {
    double S0=106.0, r=0.058, sigma=0.46;
    double T=9.0/12.0, K=100.0;
    int m=5;
    
    BSModel Model(S0,r,sigma);
    
    Eurocall Option1(T,K,m);
    Europut Option2(T,K,m);
    
    long N=30000;
    cout<<"Euro Call Price = "<<Option1.PriceByMC(Model,N)<<endl;
    cout<<"Euro put Price = "<<Option2.PriceByMC(Model,N)<<endl;

    return 0;
}
