//
//  Options06.h
//  Binomial pricer03
//
//  Created by 汪念怡 on 2/26/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#ifndef Options06_h
#define Options06_h

#include "BinModel02.h"

class EurOption{
protected:
    int N;
public:
    virtual double payoff(double z)=0;
    double PricebyCRR(BinModel mo);
};

class call:public EurOption{
private:
    double K;
public:
    int Getinputdata();
    double payoff(double z);
};

class put:public EurOption{
private:
    double K;
public:
    int Getinputdata();
    double payoff(double z);
};

class bull:public EurOption{
private:
    double K1,K2;
public:
    int Getinputdata();
    double payoff(double z);
};

class bear:public EurOption{
private:
    double K1,K2;
public:
    int Getinputdata();
    double payoff(double z);
};

#endif /* Options06_h */
