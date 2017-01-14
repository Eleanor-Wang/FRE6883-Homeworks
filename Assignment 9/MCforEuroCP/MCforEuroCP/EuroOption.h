//
//  EuroOption.h
//  MCforEuroCP
//
//  Created by 汪念怡 on 4/7/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#ifndef EuroOption_h
#define EuroOption_h

#include "BSModel01.h"

class PathDepOption{
public:
    double T;
    int m;
    double PriceByMC(BSModel Model, long N);
    virtual double Payoff(SamplePath& S)=0;
};

class Eurocall:public PathDepOption{
public:
    double K;
    Eurocall(double T_,double K_,double m_){T=T_, K=K_, m=m_;};
    double Payoff(SamplePath& S);
};

class Europut:public PathDepOption{
public:
    double K;
    Europut(double T_,double K_,double m_){T=T_, K=K_, m=m_;};
    double Payoff(SamplePath& S);
};

#endif /* EuroOption_h */
