//
//  main.cpp
//  BinModel01
//
//  Created by 汪念怡 on 2/4/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//


#include <iostream>
#include <cmath>


using namespace std;

double RiskNeutProb(double U, double D, double R)
{
    return (R-D)/(U-D);
}

double Stock(double S0,double U,double D,int n,int i)
{
    return S0*pow(1+U, i)*pow(1+D, n-i);
}

int Getinputdata(double &S0,double& U,double& D,double& R) //get the
{
    int flag = 1;
    while (flag)
    {
        flag = 0;
        cout << "Enter SO: "; cin >> S0;
        cout << "Enter U: "; cin >> U;
        cout << "Enter D: "; cin >> D;
        cout << "Enter R: "; cin >> R;
        cout << endl;
        if (U<=-1 || D<=-1 || R<=-1|| S0<0 || U<=D)
        {
            cout << "illegal data ranges" << endl;
            cout << "please reenter" << endl;
            flag = 1;
            
        }
    }
    
    if (U<=R || D>=R)
    {
        cout << "Arbitrage eists" << endl;
        cout << "Terminate program" << endl;
        return 1;
    }
    
    cout << "Data checked" << endl;
    cout << "There is no arbitrage\n " << endl;
    return 0;
}
