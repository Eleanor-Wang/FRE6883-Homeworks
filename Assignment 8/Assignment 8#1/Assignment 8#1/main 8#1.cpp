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

class F1{
public:
    double Value(double x){return x*x-2;};
    double Derive(double x){return 2*x;};
};

class F2{
private:
    double a;
public:
    F2(double a_){a=a_;};
    double Value(double x){return x*x-a;};
    double Derive(double x){return 2*x;};
};


int main(){

    cout << setiosflags(ios::fixed) << setprecision(4);
    F1 MyF1;
    F2 MyF2(3.0);
    double Acc=0.001, LEnd=0.0, REnd=2.0, Tgt=0.0;
    cout << "Root of F1 by bisect: " << SolveByBisect(MyF1,Tgt,LEnd,REnd,Acc)<< endl;
    cout << "Root of F2 by bisect: " << SolveByBisect(MyF2,Tgt,LEnd,REnd,Acc)<< endl;

    double Guess=1.0;
    cout << "Root of F1 by NR: " << SolveByNR(MyF1,Tgt,Acc,Guess)<< endl;
    cout << "Root of F1 by NR: " << SolveByNR(MyF2,Tgt,Acc,Guess)<< endl;
    cout << setiosflags(ios::fixed) << setprecision(4);
    
return 0;
}
