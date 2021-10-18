//
//  hw6-2.cpp
//  hw6
//
//  Created by Terry Lu on 2020/11/16.
//  Copyright © 2020 Terry Lu. All rights reserved.
//


/*
 
#include <iostream>
#include <algorithm>
using namespace std;
 
 
 
int a=0;
int b=0;
int c=0;
int p0=0;
int T=0;
int L=0;

 
 
 
 
int main() {
     
    //load the data
    cin>>a>>b>>c>>p0>>T>>L;
    
    
    // algorithm

    int baseOutput = 0;
    int forloopMaxOutput = 0 ;
    int forloopStopPeriod = 0 ;
    int currentPeriod = 1;
    int currentPercentage = 0;
    int periodOutput = 0;
    int maxCPeriod = 0;
    int ansOutput = 0;
    int ansPeriod = 0;
    
    
    
    maxCPeriod = T - c +2 ;
    
    
    for (int i=1;i<=T;i++){
        
        currentPercentage =  p0 - (b*currentPeriod);
        if (currentPercentage < L )
            currentPercentage = L ;
        
        
        periodOutput = a/100*currentPercentage;
        baseOutput += periodOutput;
        currentPeriod += 1;
        
    }
 
    
    
    for (int j=1;j < maxCPeriod;j++){
        
        int stopPeriod = j ;
        int stopRemainTime = -1 ;
        int P0 = p0;
        int currentOutput = 0;
        currentPeriod=1;
        
         
         for (int i=1;i<=T;i++){
               
            currentPercentage =  P0 - (b*currentPeriod);
            if (currentPercentage < L )
                currentPercentage = L ;
             
             
             if (i == j )
                stopRemainTime = c ;
                         
                         
             if( stopRemainTime > 0){
                                
                 currentPercentage = 0;
                 stopRemainTime =  stopRemainTime-1 ;
                            
                 }
             
              
               
               periodOutput = a*currentPercentage/100 ;
             
             //cout<<periodOutput;
             //cout<<'\t'<<'P'<<i<<'\t';
               currentOutput += periodOutput;
               currentPeriod += 1;
             
             
             
              if ( stopRemainTime ==  0){
                    P0 = 100;
                    currentPeriod=0;
                    stopRemainTime =  -1 ;
                 }
               
           }
        
        if (currentOutput > forloopMaxOutput){
            
            forloopMaxOutput = currentOutput;
            forloopStopPeriod = stopPeriod;
        
        }
     }
     
    
    
    
    if (forloopMaxOutput > baseOutput){
        ansOutput = forloopMaxOutput ;
        ansPeriod = forloopStopPeriod ;
        
        }
    
    else {
        
        ansOutput = baseOutput ;
        ansPeriod = 0;
        
        
    }
        
    
    
    cout<<ansPeriod<<","<<ansOutput;
     
     
    return 0 ;
     
     
}
 
 
*/
