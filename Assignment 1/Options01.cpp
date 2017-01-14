//
//  Options.cpp
//  Binomial Pricer
//
//  Created by 汪念怡 on 2/5/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//


#include <iostream>
#include <cmath>
#include "BinModel01.h"
#include "Options01.h"

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
    if (Z>K) {
        return Z-K;  // once a return will terminate the function or main();
    }
    return 0.0;
}

double PricebyCRR(double S0,double U,double D,double R, int N, double K)
{
    double q = RiskNeutProb(U,D,R);
    double Price[N+1];
    for (int i = 0; i <= N; i++) {
        Price[i] = callpayoff(Stock(S0, U, D, N, i), K);
    }
    for (int i = N-1; i>=0; i--) {
        for(int j=0;j<=i; j++){
            Price[j] = (q*Price[j+1]+(1-q)*Price[j])/(1+R);
        }
    }
    return Price[0];
//        return q;
    
}

double PricebyAsim(double S0,double U,double D,double R, int N, double K)
{
    double Price;
    double q = RiskNeutProb(U,D,R);
    double temp[N];
    for (int i=0; i<=N; i++){
        temp[i] = (Factorial(N)*1.0/Factorial(i)/Factorial(N-i))*pow(q,i)*pow((1-q),(N-i))*callpayoff(Stock(S0,U,D,N,i),K);
    }
    Price = (1/pow((1+R),N))*sumarr(temp, N);
//    return Price;
    return Price;
}

int Factorial(int i)  //factorial function
{
    if (i==0){
        return 1;
    }
    int t = i;
    for (int j=i-1; j>1; j--){
        t = t*j;
    }
    return t;
}

double sumarr(double a[],int size) //total numbers-1
{
    double s = 0;
    for (int i=0; i<=size; i++){
        s = s+a[i];
    }
    return s;
}








