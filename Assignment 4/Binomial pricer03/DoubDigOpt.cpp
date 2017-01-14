//
//  DoubleDigit.cpp
//  Binomial pricer03
//
//  Created by 汪念怡 on 2/26/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include "DoubDigOpt.h"
#include <iostream>
#include <cmath>
using namespace std;

int DoubDigitOpt::Getinputdata(){
    cout << "Enter double digital option:" << endl;
    cout << "Enter steps to expiry N: "; cin>>N;
    cout << "Enter Strike Price K1: "; cin >> K1;
    cout << "Enter Strike Price K2: "; cin >> K2;
    cout << endl;
    return 0;
}

double DoubDigitOpt::payoff(double z)
{
    if (K1<z && z<K2) return 1.0;
    return 0.0;
}

