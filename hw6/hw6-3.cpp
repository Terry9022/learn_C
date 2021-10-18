//
//  hw6-3.cpp
//  hw6
//
//  Created by Terry Lu on 2020/11/16.
//  Copyright © 2020 Terry Lu. All rights reserved.
//


 
#include <iostream>
#include <algorithm>
using namespace std;
 

 
int main() {
     
    //load the data
    
    double a=0;
    double b=0;
    double c=0;
    double p0=0;
    double T=0;
    double L=0;
    int n = 0;
    
    cin>>a>>b>>c>>p0>>T>>L>>n;
    
    int* productQuantity = new int [n];
    int* productPeriod = new int [n];
    
    
    for (int i=0;i<n;i++){
        
        cin>>productQuantity[i];
    }
    
    // algorithm
    
    productPeriod[0]=1; // 製程一定從第一期開始

    double currentOutput = 0;
    double currentPeriod = 1;
    double currentPercentage = 0;
    double periodOutput = 0;
    int indexProduct = 0;
    int indexProductPeriod = 1;

    
    for (int i=1;i<=T;i++){
        
        currentPercentage =  p0 - (b*currentPeriod);
        if (currentPercentage < L )
            currentPercentage = L ;
        
        
        periodOutput = a/100*currentPercentage;
        currentOutput += periodOutput;
        currentPeriod += 1;
        
        if (currentOutput >= productQuantity[indexProduct]){
            
            currentOutput=0;
            indexProduct+=1;
            productPeriod[indexProductPeriod]=i+1; // 將下一個產品開始的製造時間period紀錄下來
            indexProductPeriod+=1;
        }
            
        
    }
 
    
    // output the result : product manufacture period
    
    for (int i=0;i<n;i++){
        
        if (i!=n-1)
            cout<<productPeriod[i]<<',';
        else
            cout<<productPeriod[i];
        
    }
    
    
     
     
    return 0 ;
     
     
}
 
 

