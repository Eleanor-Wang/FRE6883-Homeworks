//
//  stran&Butt.cpp
//  Binomial pricer03
//
//  Created by 汪念怡 on 2/26/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include "Stran&Butt.h"
#include <iostream>
#include <cmath>
using namespace std;

int Strangle::Getinputdata(){
    cout << "Enter double-digital option:" << endl;
    cout << "Enter steps to expiry N: "; cin>>N;
    cout << "Enter Strike Price K1: "; cin >> K1;
    cout << "Enter Strike Price K2: "; cin >> K2;
    cout << endl;
    return 0;
}

int Butterfly::Getinputdata(){
    cout << "Enter double-digital option:" << endl;
    cout << "Enter steps to expiry N: "; cin>>N;
    cout << "Enter Strike Price K1: "; cin >> K1;
    cout << "Enter Strike Price K2: "; cin >> K2;
    cout << endl;
    return 0;
}

double Strangle::payoff(double z){
    if (z<K1) return K1-z;
    else if (K1 < z&&z < K2) return 0.0;
    return z-K2;
}


double Butterfly::payoff(double z){
    if (K1<z&&z<=((K1+K2)/2)) return z-K1;
    else if (((K1 + K2) / 2) < z&&z < K2) return K2-z;
    return 0.0;
}