//
//  PathDepOption03.hpp
//  MCforGreeks
//
//  Created by 汪念怡 on 4/7/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#ifndef PathDepOption03_h
#define PathDepOption03_h

#include "BSModel01.h"

class PathDepOption{
public:
    double T,Price,PricingError,delta,gamma;
    int m;
    virtual double Payoff(SamplePath& S)=0;
    double PriceByMC(BSModel Model,long N,double epsilon);
};

class ArthmAsianCall:public PathDepOption{
public:
    double K;
    ArthmAsianCall(double T_,double K_,int m_){T=T_,K=K_,m=m_;}
    double Payoff(SamplePath& S);
};


#endif /* PathDepOption03_h */
