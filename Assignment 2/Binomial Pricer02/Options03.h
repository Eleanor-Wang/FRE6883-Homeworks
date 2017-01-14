//
//  Header.h
//  Binomial Pricer02
//
//  Created by 汪念怡 on 2/12/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#ifndef Header_h
#define Header_h

int Getinputdata(int& N,double& K);
double callpayoff(double Z, double K);
double putpayoff(double Z, double K);
double dig_callpayoff(double Z,double K);
double dig_putpayoff(double Z,double K);
double PricebyCRR(double S0,double U,double D,double R, int N, double K, double(*payoff)(double Z,double K));

#endif /* Header_h */
