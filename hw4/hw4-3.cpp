//
//  hw4-3.cpp
//  hw4
//
//  Created by Terry Lu on 2020/10/19.
//  Copyright © 2020 Terry Lu. All rights reserved.
//

#include <iostream>
using namespace std;


int main() {

    
    //load the data
    
    int n =0;
    cin>>n;
    
    int* cost = new int[n];
    int* build = new int[n];
    
    for(int i = 0; i < n; i++){
        cin >> cost[i];
        build[i]=1;
    }
    
    //benefit 2d array matrix
    int matrix[100][100]={0};
  
    
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
    
    
    // algorithm
    
    // first round profit counting
    int recent_profit =0;
    int sum_benefit=0;
    int sum_cost=0;
   
    for(int i = 0; i < n; i++){
        for (int j = 0 ; j < n; j++){
               sum_benefit+=matrix[i][j];
               }
           }
    sum_benefit=sum_benefit/2;
    
    
    for(int i = 0; i < n; i++)
        sum_cost+=cost[i];
    
    
    recent_profit=sum_benefit-sum_cost;
    
    
    // after first round, we use algorithm to find the one we want to discard.
    
    
    
    int loop_profit_smallest = 0;
    int loop_n = 0;
    bool this_round = false;
    
    loop_profit_smallest=recent_profit;
   
    do {
        this_round = false;
    
   for(int h = 0; h < n; h++){
       
       
        int loop_profit = 0;
        int loop_benefit = 0;
        int loop_cost = 0;
       
       
    for(int i = 0; i < n; i++){
        if (i==h || build[i]==0)
            continue;
        
        for (int j = 0 ; j < n; j++){
            if (j==h|| build[j]==0)
                continue;
               loop_benefit+=matrix[i][j];
               }
           }
       
       loop_benefit=loop_benefit/2;
    
    
       for(int i = 0; i < n; i++){
        if (i==h || build[i]==0)
        continue;
           
        loop_cost+=cost[i];}
    
    
        loop_profit=loop_benefit-loop_cost;


       if (loop_profit>recent_profit){
           loop_n=h+1;
           loop_profit_smallest=loop_profit;
           recent_profit=loop_profit;
           this_round = true;
       }
       
   }
        if (this_round){
            build[loop_n-1]=0;}
        else{break;}
    
    } while(true);
    
    
    
    for(int i = 0; i < n; i++)
        if (i==n-1)
        cout<<build[i]<<';';
    else
        cout<<build[i]<<',';
    cout<<loop_profit_smallest;

    
    
    return 0;
}



