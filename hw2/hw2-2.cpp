//
//  hw2-2.cpp
//  hw2
//
//  Created by Terry Lu on 2020/10/2.
//  Copyright © 2020 Terry Lu. All rights reserved.
//
/*
#include <iostream>
using namespace std;

int main() {
    
    int n = 0;
    int x = 0;
    int inputTNow=0,inputRNow=0,inputTLast=0,inputRLast=0;
    int ans = 0;
    int remainX = 0;

    cin>>n>>x;

    for (int i =0 ; i < n; i++ ){
        
        cin>>inputTNow>>inputRNow;
        
        remainX= x - inputTLast;
        
        if (x<=inputTNow){
            ans= ans + remainX * inputRNow;
            break;
        }
        else {
            ans = ans + (inputTNow-inputTLast)*inputRNow;
            inputTLast = inputTNow;
            inputRLast = inputRNow;
            
            }
            
        }
    
    cout<<ans;
        
    
    return 0;
}

*/
