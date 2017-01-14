//
//  main.cpp
//  trapezoidal approximation
//
//  Created by 汪念怡 on 2/18/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include <iostream>
using namespace std;

class Deflnt{
private:
    double a,b;
    double (*f)(double x);
public:
    Deflnt(double aa, double bb, double(*ff)(double x));
    double ByTrapzoid(int N);
    double BySimpson(int N);
};

Deflnt::Deflnt(double aa, double bb, double(*ff)(double x)){
    a = aa;
    b = bb;
    f = ff;
}
double Deflnt::ByTrapzoid(int N){
    double s = (*f)(a)+(*f)(b);
    double h = (b-a)/N;
    for (int i=1; i<N; i++){
        s+= 2*(*f)(a+h*i);
    }
    s = s*h/2;
    return s;
}
double Deflnt::BySimpson(int N){
    double h = (b-a)/N, r;
    char m=0;
    double s =(*f)(a)+(*f)(b);
    for (int i = 1; i<N; i++){
        r = (*f)(a+h*i);
        m = !m;
        s+= 2*r*(m+1);
    }
    s = s*h/3;
    return s;
}


double fun(double x){
    return x*x*x+x*x;
}

int main() {
    int N;
    cout << "please enter the steps: " << endl; cin >> N;
    Deflnt sample(2.5,3.5,fun);
    
    cout << "result of trapezoidal approximation = " <<sample.ByTrapzoid(N) << endl;
    cout << "result of Simpson approximation = " <<sample.BySimpson(N) << endl;
    
    return 0;
}
