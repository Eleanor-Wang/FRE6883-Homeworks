//
//  Header.h
//  Assignment 7
//
//  Created by 汪念怡 on 3/11/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#ifndef Options07_h
#define Options07_h


class BinModel{
protected:
    int N;
    double S0,r,sigma,T,K;
public:
    BinModel(double S0_,double r_,double sigma_,double T_, int N_);
    double U();
    double D();
    double R();
    double RiskNeutProb(){return (R()-D())/(U()-D());};
    double Stock(int n, int i);
    
};

class Amoption{
protected:
    int N;
public:
    Amoption(int N_){N=N_;}
    virtual double Payoff(double z)=0;
    double PriceBySnell(BinModel Model);
};

class Call:public Amoption{
private:
    double K;
public:
    Call(int N_, double K_):Amoption(N_){K=K_;}
    double Payoff(double z);
};


#endif /* Header_h */
