//
//  main.cpp
//  Assignment 7
//
//  Created by 汪念怡 on 3/11/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include <iostream>
#include "Options07.h"
#include <cmath>
#include <iomanip>
using namespace std;

//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}


int main(){
    BinModel r1(106.0,0.058,0.46,0.75,8);
    Call option01(8,100);
        cout<<"U = "<<r1.U() <<endl;
        cout<<"D = "<<r1.D() <<endl;
    cout<<"R = "<<r1.R() <<endl;
        cout<< "American call option price = "<< option01.PriceBySnell(r1)<<endl;
    cout << setiosflags(ios::fixed) << setprecision(5);
    return 0;
}