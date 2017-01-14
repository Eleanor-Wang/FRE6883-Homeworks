//
//  Option03.cpp
//  Binomial Pricer02
//
//  Created by 汪念怡 on 2/12/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "BinModel01.h"
#include "Options03.h"

using namespace std;

int Getinputdata(int& N,double& K)
{
    cout << "Enter steps to expiry N: "; cin >> N;
    cout << "Enter Strike Price K: "; cin >> K;
    cout << endl;
    return 0;
}

double callpayoff(double Z, double K)
{
    if (Z>K) return Z-K;
    return 0.0;
}

double putpayoff(double Z, double K)
{
    if (Z<K) return K-Z;
    return 0.0;
}

double dig_callpayoff(double Z,double K)
{
    if (Z>K) return 1.0;
    return 0.0;
}

double dig_putpayoff(double Z,double K)
{
    if (Z<K) return 1.0;
    return 0.0;
}

double PricebyCRR(double S0,double U,double D,double R, int N, double K, double(*payoff)(double Z,double K)) //function poiter: (callpayoff function) passes in with the variable "payoff"
{
    double q = RiskNeutProb(U,D,R);
    double Price[N+1];
    for (int i = 0; i <= N; i++) {
        Price[i] = payoff(Stock(S0,U,D,N,i),K);
    }
    for (int i = N-1; i>=0; i--) {
        for(int j=0;j<=i; j++){
            Price[j] = (q*Price[j+1]+(1-q)*Price[j])/(1+R);
        }
    }
    return Price[0];
}


















