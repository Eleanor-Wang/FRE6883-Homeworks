//
//  Options06.cpp
//  Binomial pricer03
//
//  Created by 汪念怡 on 2/26/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include "BinModel02.h"
#include "Options06.h"
#include <iostream>
#include <cmath>
using namespace std;


double EurOption::PricebyCRR(BinModel mo){
    double q = mo.RiskNeutProb();
    double Price[N+1];
    for (int i = 0; i <= N; i++) {
        Price[i] = payoff(mo.Stock(N,i));
    }
    for (int i = N-1; i>=0; i--) {
        for(int j=0;j<=i; j++){
            Price[j] = (q*Price[j+1]+(1-q)*Price[j])/(1+mo.GetR());
        }
    }
    return Price[0];
}
//-----------payoff----------------------
double call::payoff(double z){
    if (z>K) return z-K;
    return 0.0;
}

double put::payoff(double z){
    if (z>K) return 0.0;
    return K-z;
}

double bull::payoff(double z){
    if (z<=K1) return 0.0;
    else if (z<K2) return z-K1;
    return K2-K1;
}

double bear::payoff(double z){
    if (z<=K1) return K2-K1;
    else if (z<K2) return K2-z;
    return 0.0;
}

//-----------get N K------------------------
int call::Getinputdata(){
    cout << "Enropean call option:"<<endl;
    cout << "Enter steps to expiry N: "; cin >> N;//EurOption.N , AmOption.N  ???????
    cout << "Enter Strike Price K: "; cin >> K;
    cout << endl;
    return 0;
}

int put::Getinputdata(){
    cout << "Enropean put option:"<<endl;
    cout << "Enter steps to expiry N: "; cin >> N;
    cout << "Enter Strike Price K: "; cin >> K;
    cout << endl;
    return 0;
}
int bull::Getinputdata(){
    cout << "Enropean bull option:"<<endl;
    cout << "Enter steps to expiry N: "; cin >> N;
    cout << "Enter Strike Price K1: "; cin >> K1;
    cout << "Enter Strike Price K2: "; cin >> K2;
    cout << endl;
    return 0;
}
int bear::Getinputdata(){
    cout << "Enropean bear option:"<<endl;
    cout << "Enter steps to expiry N: "; cin >> N;
    cout << "Enter Strike Price K1: "; cin >> K1;
    cout << "Enter Strike Price K2: "; cin >> K2;
    cout << endl;
    return 0;
}
