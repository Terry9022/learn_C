//
//  Q4.cpp
//  midterm2
//
//  Created by Terry Lu on 2020/12/1.
//  Copyright © 2020 Terry Lu. All rights reserved.
//
/*
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int n = 0;
    int k = 0;
    int s = 0;
    int t = 0;
    
    cin>>n>>k>>s>>t;
    
    
    //price 2d array matrix
    int matrix[20][20]={0};
    
   // make the benefit symmetic matrix
    
    for(int i = 0; i < n-1; i++){
        for (int j = 0 ; j < n-1-i; j++){
            cin>>matrix[i][j+1+i];
            }
        }
    
    for(int i = 0; i < n; i++){
    for (int j = 0 ; j <= i; j++){
       matrix[i][j]=matrix[j][i];
       }
   }
    
    
    
    int ans=0;
    int transfer_time = k;
    int min_total=999999;
    
    if (k==0)
        ans=matrix[s-1][t-1];
    
    
    if (k==1){
        
        
        for(int i = 0; i < n; i++){
             
             if (i == s-1 || i == t-1)
                 continue;
            int first_round=matrix[s-1][i];
            int second_round=matrix[i][t-1];
            int total = first_round+second_round;
             
            if (total<min_total)
                min_total=total;
                
            }
        
        ans=min_total;
        }
    
       
    
    
    
    
    cout<<ans;
    
    
    
   
    return 0;
}
*/
