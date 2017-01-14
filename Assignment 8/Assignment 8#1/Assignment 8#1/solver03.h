//
//  solver03.h
//  assignment 8
//
//  Created by 汪念怡 on 3/25/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#ifndef solver03_h
#define solver03_h

template<typename Function> double SolveByBisect(Function &Fct,double Tgt, double LEnd, double REnd, double Acc){
    double left=LEnd, right=REnd, mid=(LEnd+REnd)/2;
    double y_left=Fct.Value(left)-Tgt, y_mid=Fct.Value(mid)-Tgt;
    
    for (;mid-left>Acc;){
        if ((y_left<0&&y_mid<0) || (y_left>0&&y_mid>0)){
            left=mid, y_left=y_mid;}
        else right=mid;
        mid=(right+left)/2; y_mid=Fct.Value(mid)-Tgt;
    }
    return mid;
}

template<typename Function> double SolveByNR(Function &Fct,double Tgt,double Acc,double Guess){
    double x_prev=Guess, x_next=x_prev-(Fct.Value(x_prev)-Tgt)/Fct.Derive(x_prev);
    for (;x_prev-x_next>Acc||x_next-x_prev>Acc;){
        x_prev=x_next;
        x_next=x_prev-(Fct.Value(x_prev)-Tgt)/Fct.Derive(x_prev);
    }
    return x_next;
}

#endif /* solver03_h */
