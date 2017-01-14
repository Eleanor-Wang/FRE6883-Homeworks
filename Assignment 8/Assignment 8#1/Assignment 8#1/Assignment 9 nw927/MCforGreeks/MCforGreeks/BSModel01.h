//
//  BSModel01.h
//  Assignment9 #1
//
//  Created by 汪念怡 on 4/2/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#ifndef BSModel01_h
#define BSModel01_h

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


typedef vector<double> SamplePath;

class BSModel{
public:
    double S0,r,sigma,a;
    BSModel(double S0_, double r_,double sigma_){
        S0=S0_, r=r_, sigma=sigma_;
//     srand(a);
        srand(time(NULL));
        
    }
    void GenerateSamplePath(double T,int m, SamplePath& S);
};



#endif /* BSModel01_h */
