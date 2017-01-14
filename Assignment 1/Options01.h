//
//  Options01.h
//  Binomial Pricer
//
//  Created by 汪念怡 on 2/5/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#ifndef Options01_h
#define Options01_h

double callpayoff(double Z, double K);
double PricebyCRR(double S0,double U,double D,double R, int N, double K);
int Getinputdata(int& N,double& K);
int Factorial(int i);
double PricebyAsim(double S0,double U,double D,double R, int N, double K); //asignment 1;
double sumarr(double a[],int size);  //sum of array

#endif /* Options01_h */
