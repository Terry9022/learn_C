//
//  hw3-2.cpp
//  hw3
//
//  Created by Terry Lu on 2020/10/10.
//  Copyright © 2020 Terry Lu. All rights reserved.
//
/*
#include <iostream>
using namespace std;

int main() {
    
    int n = 0;
    int k = 0;
    int inputNow=0;
    int start=0;
    int end=0;
    int sum=0;
    int sumBiggest=-99999;
    int startAns=0;
    int endAns=0;
    int length=0;
    int lengthAns=0;
    
    cin>>n>>k;
    
 
    int* numberForCount = new int[n];
    int* numberForReal = new int[n];
    
    for (int i =0 ; i < n; i++){
        cin>>inputNow;
        if (inputNow%k==0 && inputNow>0){
            numberForCount[i]=0;
            numberForReal[i]=inputNow;}
        else {
            numberForCount[i]=inputNow;
            numberForReal[i]=inputNow;
        }
        
    }

    
     for (int i =0 ; i < n; i++){
         start = i;
        
         for(int j = start; j < n; j++){
             end=j;
             sum=0;
             
             for(int k = start ; k <= end; k++){
                 sum=sum+numberForCount[k];}
             
             length=end-start;
             
             
             if (sum > sumBiggest){
                 
                 sumBiggest=sum;
                 startAns=start;
                 endAns=end;
                 lengthAns=length;
             }
             
             else if (sum == sumBiggest && lengthAns<=length){
                 
                 sumBiggest=sum;
                 startAns=start;
                 endAns=end;
                 lengthAns=length;
             }
         }
     }
    
    startAns=startAns+1;
    endAns=endAns+1;
 
    //for (int i =0 ; i < n; i++){cout<<numberForCount[i]<<'.';}
         
    cout<<startAns<<','<<endAns<<','<<sumBiggest;
   

    
    return 0 ;
}
*/
