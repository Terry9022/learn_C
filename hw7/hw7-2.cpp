//
//  hw7-2.cpp
//  hw7
//
//  Created by Terry Lu on 2020/11/29.
//  Copyright © 2020 Terry Lu. All rights reserved.
//


/*
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
    
    int* productQuantity = new int [n+1];
    
    // include the last product's finish period+1
    int* productActualPeriod = new int [n+1];
    
    int* productDemandPeriod = new int [n+1];
    
    
    for (int i=0;i<n;i++){
        
        cin>>productQuantity[i];
    }
    
    for (int i=0;i<n;i++){
        
        cin>>productDemandPeriod[i];
    }
    
    
    for (int i=0;i<n+1;i++){
        
        productActualPeriod[i]=0;
    }
     
    // 重新安排生產順序
    
    int** metrix = new int*[n+1];
       for(int i = 0; i < n; ++i)
           metrix[i] = new int[3];
       
       
       
       for (int i=0;i<n;i++){
           
           metrix[i][0]=productQuantity[i];
           metrix[i][1]=productDemandPeriod[i];
           metrix[i][2]=i;
       }
    
       std::sort(metrix, metrix+n, [](int* a, int* b){
            return a[2] < b[2]; // 升序排列
        });
    
    
       std::sort(metrix, metrix+n, [](int* a, int* b){
        return a[0] < b[0]; // 升序排列
    });
       
       
       std::sort(metrix, metrix+n, [](int* a, int* b){
           return a[1] < b[1]; // 升序排列
       });
       
       
       
       for (int i=0;i<n;i++){
           
           productQuantity[i]=metrix[i][0];
           productDemandPeriod[i]=metrix[i][1];
       }
       

    // algorithm
    
    productActualPeriod[0]=1; // 製程一定從第一期開始

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
        
        
        periodOutput = a*0.01*currentPercentage;
        currentOutput += periodOutput;
        currentPeriod += 1;
        
        if (currentOutput >= productQuantity[indexProduct]){
            
            currentOutput=0;
            indexProduct+=1;
            productActualPeriod[indexProductPeriod]=i+1; // 將下一個產品開始的製造時間period紀錄下來
            indexProductPeriod+=1;
            if (indexProductPeriod == n+1)
                break;
        }
            
        
    }
    
 
    
    // compute original delay time
        
    int originalDelayTime=0;
    
    for (int i=0;i<n;i++){
        
        if (productActualPeriod[i+1]-1 >  productDemandPeriod[i])
            originalDelayTime += (productActualPeriod[i+1]-1)-productDemandPeriod[i];
        
    }
    
    
    
    
    // decide when to fix the machine
    // compute fixed delay time
    
    double forloopMinDelay = 9999999999 ;
    int forloopStopPeriod = 0 ;
    
    int* productActualPeriod2 = new int [n+1];
    int* productActualPeriod3 = new int [n+1];
    
    for (int i=0;i<n+1;i++){
        productActualPeriod2[i]=0;
        productActualPeriod3[i]=0;
    }
    
    productActualPeriod2[0]=1; // 製程一定從第一期開始
       
    
    
    for (int j=0 ;j < n ;j++){
        
        int stopPeriod = 0;
        int stopRemainTime = -1 ;
        int P0 = p0;
        int DelayTime=0;
        
        currentOutput = 0;
        currentPeriod = 1;
        currentPercentage = 0;
        periodOutput = 0;
        indexProduct = 0;
        indexProductPeriod = 1;
        stopRemainTime = -1 ;
        P0 = p0;
        DelayTime=0;
        stopPeriod  = productActualPeriod[j] ;
        
        
        
        
        if (stopPeriod + c > T)
            continue;
        
        
      
        
           
           for (int i=1;i<=T;i++){
               
               currentPercentage =  P0 - (b*currentPeriod);
               if (currentPercentage < L )
                   currentPercentage = L ;
               
               if (i == stopPeriod )
                  stopRemainTime = c ;
                           
                           
               if( stopRemainTime > 0){
                                  
                   currentPercentage = 0;
                   stopRemainTime =  stopRemainTime-1 ;
                              
                   }
               
               
               periodOutput = a*0.01*currentPercentage;
               currentOutput += periodOutput;
               currentPeriod += 1;
               
               if ( stopRemainTime ==  0){
                                  P0 = 100;
                                  currentPeriod=0;
                                  stopRemainTime =  -1 ;
                               }
               
               if (currentOutput >= productQuantity[indexProduct] ){
                   
                   //cout<<stopPeriod<<":"<<"Y"<<",";
                   currentOutput=0;
                   indexProduct+=1;
                   productActualPeriod2[indexProductPeriod] = i + 1;  //將下一個產品開始的製造時間period紀錄下來
                   indexProductPeriod+=1;
                   
                   if (indexProductPeriod == n+1)
                        break;
               }
               
              
               
                    }
            
        
               DelayTime=0;
         
            
               for (int d=0;d<n;d++){
                
                   if (productActualPeriod2[d+1]-1 >  productDemandPeriod[d])
                       DelayTime += (productActualPeriod2[d+1]-1)-productDemandPeriod[d];
            
                    }
         
        
               if (DelayTime < forloopMinDelay){
            
                   forloopMinDelay=DelayTime;
                   forloopStopPeriod=stopPeriod;
                   for (int e=0;e<n+1;e++){productActualPeriod3[e]=productActualPeriod2[e];}
               }
        
        
           
        
    }
    

    
    
    for (int i=0;i<n+1;i++){
        cout<<productActualPeriod[i]<<',';
    }
    cout<<'\n';
    for (int i=0;i<n+1;i++){
        cout<<productActualPeriod3[i]<<',';
    }
    cout<<'\n';
    
   
    
    
    // output the answer
    
    int ansFixPeriod=0;
    int ansDelayTime=0;
    
    if (originalDelayTime<=forloopMinDelay){
        ansDelayTime=originalDelayTime;
        ansFixPeriod=0;
    }
    
    else{
        
        
        ansDelayTime=forloopMinDelay;
        ansFixPeriod=forloopStopPeriod;
        
    }
    
    
    cout<<ansFixPeriod<<','<<ansDelayTime;
    
    
    return 0 ;
     
     
}
 
*/


