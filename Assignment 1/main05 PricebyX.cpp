//
//  main05 PricebyCRR.cpp
//  Binomial Pricer
//
//  Created by 汪念怡 on 2/5/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include "BinModel01.h"
#include "Options01.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double S0,R,U,D,K; int N;
    
    if (Getinputdata(S0, U, D, R)==1) {
        return 1;
    }
    Getinputdata(N,K);
    cout << "European call option price: " << PricebyAsim(S0,U,D,R,N,K) << endl<< endl;
    
    return 0;
 
}

