//
//  main 17.cpp
//  assignment 8
//
//  Created by 汪念怡 on 3/25/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//


#include <iostream>
#include <cmath>
#include <iomanip>
#include"solver03.h"
using namespace std;

class Bond{
private:
    int T;
    double C, F;
public:
    Bond(int T_, double F_, double C_){T=T_,F=F_,C=C_;};
    double getF(){return F;};
    double getT(int x){return x+1;};
    double getC(){return C;};
    double Value(double x){
        double s=F*exp(-x*T);
        for (int i=1;i<=T;i++){
            s+=C*exp(-x*i);
        }
        return s;};
    
    double Derive(double x){
        double s=-T*F*exp(-x*T);
        for (int i=1;i<=T;i++){
            s+=-C*i*exp(-x*i);
        }
        return s;};
};


int main(){

    cout << setiosflags(ios::fixed) << setprecision(4);
    Bond Bond1(3.0,100.0,1.2);
    double Acc=0.0001, LEnd=0.0, REnd=1.0, Tgt=98.56, Guess=0.2;
    
    cout << "F = "<<Bond1.getF()<<endl;
    cout << "T = "<<Bond1.getT(2)<<endl;
    cout << "coupons:\n" << "C0 = "<< Bond1.getC()<< "\nC1 = "<< Bond1.getC()<< "\nC2 = " << Bond1.getC()<<endl;
    cout << "tenors:\n" << "T0 = "<< Bond1.getT(0)<< "\nT1 = "<< Bond1.getT(1)<< "\nT2 = " << Bond1.getT(2)<<endl;
    cout << "P = "<<Bond1.Value(SolveByBisect(&Bond1,Tgt,LEnd,REnd,Acc))<<endl<<endl;
    
    cout << "Yield by bisect: " << SolveByBisect(&Bond1,Tgt,LEnd,REnd,Acc)<< endl;
    cout << "Yield by NR: " << SolveByNR(&Bond1,Tgt,Acc,Guess)<< endl;
    
return 0;
}
