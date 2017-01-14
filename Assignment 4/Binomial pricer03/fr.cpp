//
//  fr.cpp
//  Binomial pricer03
//
//  Created by 汪念怡 on 2/27/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

class Trapezoid: public DefInt
{
private:
    double ByTrapezoid(int N);
public:
    Trapezoid(int N_, double a_, double b_, double (*f_)(double x)):DefInt(N_, a_, b_, f_) {}
    ~Trapezoid() {}
    virtual double ByNumApprximation()
    { return ByTrapezoid(N); }
};

class Simpson: public DefInt
{
private:
    double BySimpson(int N);
public:
    Simpson(int N_, double a_, double b_, double (*f_)(double x)):DefInt(N_, a_, b_, f_) {}
    ~Simpson() {}
    virtual double ByNumApprximation()
    { return BySimpson(N); }
};

double Trapezoid::ByTrapezoid(int N)
{
    cout << "ByTrapezoid: ";
    double h=(b-a)/N;
    double Result=0.5*f(a);
    for (int n=1; n<N; n++)
        Result+=f(a+n*h);
    Result+=0.5*f(b);
    return Result*h;
}

double Simpson::BySimpson(int N)
{
    cout	<< "BySimpson: ";
    double h=(b-a)/N;
    double Result=f(a);
    for (int n=1; n<N; n++)
        Result+=4*f(a+n*h-0.5*h)+2*f(a+n*h);
    Result+=4*f(b-0.5*h)+f(b);
    return Result*h/6;
}

#include <iostream>
using namespace std;
double f(double x){return x*x*x-x*x+1;}

class DefInt
{
protected:
    int N;
    double a,b;
    double (*f)(double x);
    DefInt *ptrs[2];
public:
    
    DefInt():N(0),a(0),b(0),f(0) {}
    DefInt(int N_, double a_, double b_, double
           (*f_)(double x)):N(N_),a(a_),b(b_),f(f_) {}
    
    virtual ~DefInt() { }
    virtual double ByNumApprximation(void)
    { return 0.0; };
    
    void SetPtr1(DefInt * ptr1_)
    { ptrs[0] = ptr1_; }
    
    
    void SetPtr2(DefInt * ptr2_)
    { ptrs[1] = ptr2_; }
    
    DefInt * GetPtr1(void) { return ptrs[0]; }
    DefInt * GetPtr2(void) { return ptrs[1]; }
    
};
// The main() function
int main()
{
    double a=1.0;
    double b=2.0;
    int N=1000;
    Trapezoid Approximantion1(N, a, b, f);
    Simpson Approximantion2(N, a, b, f);
    DefInt * Approximantion = new DefInt();;
    Approximantion->SetPtr1(&Approximantion1);
    Approximantion->SetPtr2(&Approximantion2);
    cout <<  Approximantion-> GetPtr1()->
    ByNumApprximation() << endl;
    cout << Approximantion->GetPtr2()->
    ByNumApprximation() << endl;
    delete Approximantion;
    getchar();
    return 0;
}
