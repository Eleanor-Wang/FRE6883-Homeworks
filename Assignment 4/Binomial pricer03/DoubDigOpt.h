//
//  DoubleDigit.hpp
//  Binomial pricer03
//
//  Created by 汪念怡 on 2/26/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#ifndef DoubDigOpt_h
#define DoubDigOpt_h

#include "Options06.h"

class DoubDigitOpt:public EurOption{
private:
    double K1,K2;
public:
    int Getinputdata();
    double payoff(double z);
};

#endif /* DoubDigOpt_h */
