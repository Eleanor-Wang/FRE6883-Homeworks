//
//  stran&Butt.hpp
//  Binomial pricer03
//
//  Created by 汪念怡 on 2/26/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#ifndef Stran_Butt_h
#define Stran_Butt_h

#include "Options06.h"

class Butterfly:public EurOption{
private:
    double K1, K2;
public:
    int Getinputdata();
    double payoff(double z);
};

class Strangle:public EurOption{
private:
    double K1, K2;
public:
    int Getinputdata();
    double payoff(double z);
};

#endif /* Stran_Butt_h */
