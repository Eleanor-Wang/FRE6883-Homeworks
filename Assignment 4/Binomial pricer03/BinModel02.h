//
//  BinModel02.hpp
//  Binomial pricer03
//
//  Created by 汪念怡 on 2/26/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#ifndef BinModel02_h
#define BinModel02_h

class BinModel{
private:
    double S0,U,D,R;
public:
    double RiskNeutProb();
    double Stock(int n, int i);
    int Getinputdata();
    double GetR();
};


#endif /* BinModel02_h */
