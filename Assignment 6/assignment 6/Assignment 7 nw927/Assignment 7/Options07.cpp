//
//  Options07.cpp
//  Assignment 7
//
//  Created by 汪念怡 on 3/11/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include "Options07.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

BinModel::BinModel(double S0_,double r_,double sigma_,double T_, int N_){
    S0 = S0_; r=r_; sigma=sigma_; T=T_; N=N_;
}
double BinModel::U(){
    return exp((r-pow(sigma,2)*0.5)*T/N+sigma*pow(T/N,0.5))-1;
}
double BinModel::D(){
    return exp((r-pow(sigma,2)*0.5)*T/N-sigma*pow(T/N,0.5))-1;
}

double BinModel::R(){return exp(r*T/N)-1;}


double BinModel::Stock(int n, int i){return S0*pow(1+U(), i)*pow(1+D(), n-i);}

double Amoption::PriceBySnell(BinModel Model){
    double q = Model.RiskNeutProb();
    vector<double> Price(N+1);
    double ContVal;
    
    for (int i = 0;i<=N;i++){
        Price[i] = Payoff(Model.Stock(N,i));
    }
    
    for (int n=N-1;n>=0;n--){
        for (int i=0; i<=n; i++){
        ContVal = (q*Price[i+1]+(1-q)*Price[i])/(1+Model.R());
        Price[i] = Payoff(Model.Stock(n,i));
        if (ContVal>Price[i]) Price[i]= ContVal;
        }
    }
return Price[0];
}

double Call::Payoff(double z){if (z<K) return 0; return z-K;}



