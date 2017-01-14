//
//  main.cpp
//  Binomial Pricer02
//
//  Created by 汪念怡 on 2/12/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include "BinModel01.h"
#include "Options03.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double S0,R,U,D,K; int N;

    if (Getinputdata(S0, U, D, R)==1) {
        return 1;
    }
    
    cout << "Enter call option data:" << endl;
    Getinputdata(N,K);
    cout << "European call option price: " << PricebyCRR(S0,U,D,R,N,K,callpayoff) <<endl;
    cout << "European digit call price: " << PricebyCRR(S0,U,D,R,N,K,dig_callpayoff) << endl <<endl;

    Getinputdata(N,K);
    cout << "European put option price: " << PricebyCRR(S0,U,D,R,N,K,putpayoff) << endl;
    cout << "European digit put price: " << PricebyCRR(S0,U,D,R,N,K,dig_putpayoff) << endl <<endl;

    return 0;
}