//
//  main.cpp
//  Binomial pricer03
//
//  Created by 汪念怡 on 2/26/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "BinModel02.h"
#include "Options06.h"
#include "Stran&Butt.h"
#include "DoubDigOpt.h"

using namespace std;

int main(){
    BinModel Model;
    if (Model.Getinputdata()==1) return 1;
    
    call Option1;
    Option1.Getinputdata();
    cout << "European call option price: " << Option1.PricebyCRR(Model) <<endl<<endl;
    
    put Option2;
    Option2.Getinputdata();
    cout << "European put option price: " << Option2.PricebyCRR(Model) <<endl<<endl;
//    
//    bull Option3;
//    Option3.Getinputdata();
//    cout << "European bull option price: " << Option3.PricebyCRR(Model) <<endl<<endl;
//    
//    bear Option4;
//    Option4.Getinputdata();
//    cout << "European bear option price: " << Option4.PricebyCRR(Model) <<endl<<endl;
//    
    
    DoubDigitOpt Option3;
    Option3.Getinputdata();
    cout << "European Double Digital option price: " << Option3.PricebyCRR(Model) <<endl<<endl;
    
    
    Strangle Option4;
    Option4.Getinputdata();
    cout << "European Strangle option price: " << Option4.PricebyCRR(Model) <<endl<<endl;
    
    
    Butterfly Option5;
    Option5.Getinputdata();
    cout << "European Butterfly spread option price: " << Option5.PricebyCRR(Model) <<endl<<endl;
    
    return 0;
}







