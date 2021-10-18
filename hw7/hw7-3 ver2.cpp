//
//  hw7-3 ver2.cpp
//  hw7
//
//  Created by Terry Lu on 2020/12/6.
//  Copyright © 2020 Terry Lu. All rights reserved.
//

/*
 
#include <iostream>
using namespace std;


int main() {

    
    //load the data
    
    int n =0;
    int m =0;
    
    cin>>n>>m;
    
    int init_size = 4*(m/n);
    
    int* cost = new int[n];
    int* build = new int[n];
    //dynamic 2d array matrix
       int** metrix_number = new int*[n];
       int** metrix_benefit = new int*[n];
       int* metrix_current_size = new int [n];
       int* metrix_max_size = new int [n];
    
    for(int i = 0; i < n; i++){
        cin >> cost[i];
        build[i]=1;
        
        metrix_number[i] = new int[init_size];
        metrix_benefit[i] = new int[init_size];
        metrix_current_size[i] = 0;
        metrix_max_size[i] = init_size;
        
    }

    
    // read the benefit
    // benefit into metrix
    
    
    for(int i = 0; i < m; i++){
        
        int first_airport = 0;
        int second_airport = 0;
        int their_benefit = 0;
        
        cin>>first_airport>>second_airport>>their_benefit;
        
        first_airport=first_airport-1;
        second_airport=second_airport-1;
        
        // double the first_airport array
        if (metrix_current_size[first_airport] == metrix_max_size[first_airport]){
            
            int current_max_size= metrix_max_size[first_airport];
            int new_max_size= 2*current_max_size;
            int* new_array1 = new int[new_max_size];
            int* new_array2 = new int[new_max_size];
            
            
            for(int j = 0; j < current_max_size; j++){
                    new_array1[j]= metrix_number[first_airport][j]  ;
                    new_array2[j]= metrix_benefit[first_airport][j]  ;
                }
            
        
        delete [] metrix_number[first_airport];
        delete [] metrix_benefit[first_airport];
        
        metrix_number[first_airport] = new_array1 ;
        metrix_benefit[first_airport] = new_array2 ;
            
        metrix_max_size[first_airport] = new_max_size;
        }
        
        // double the second_airport array
        if (metrix_current_size[second_airport] == metrix_max_size[second_airport]){
                 
                 int current_max_size= metrix_max_size[second_airport];
                 int new_max_size= 2*current_max_size;
                 int* new_array1 = new int[new_max_size];
                 int* new_array2 = new int[new_max_size];
                 
                 for(int j = 0; j < current_max_size; j++){
                         new_array1[j]= metrix_number[second_airport][j]  ;
                         new_array2[j]= metrix_benefit[second_airport][j]  ;
                     }
                 
             
             delete [] metrix_number[second_airport];
             delete [] metrix_benefit[second_airport];
             
             metrix_number[second_airport] = new_array1 ;
             metrix_benefit[second_airport] = new_array2 ;
            
            metrix_max_size[second_airport] = new_max_size;
             }
        
        
        // input the data to metrix
        int first_airport_index = metrix_current_size[first_airport] ;
        int second_airport_index = metrix_current_size[second_airport] ;
        
        metrix_number[first_airport][first_airport_index] = second_airport;
        metrix_number[second_airport][second_airport_index] = first_airport;
        metrix_benefit[first_airport][first_airport_index]=their_benefit;
        metrix_benefit[second_airport][second_airport_index]=their_benefit;
        // update the current size in order to check the max size in the future
        metrix_current_size[first_airport]+=1;
        metrix_current_size[second_airport]+=1;
        
        
    }
    
     
    // algorithm
    
    // first round profit counting
    int recent_profit =0;
    int sum_benefit=0;
    int sum_cost=0;
   
    for(int i = 0; i < n; i++){
        
        if ( metrix_current_size[i]!=0){
            
            for (int j = 0 ; j < metrix_current_size[i]; j++){
                         sum_benefit+=metrix_benefit[i][j];
                         }
            
        }
        
        sum_cost+=cost[i];
      
           }
    
    sum_benefit=sum_benefit/2;
    
    
    recent_profit=sum_benefit-sum_cost;
    
    
    // after first round, we use algorithm to find the one we want to discard.
    
    
    int loop_profit_smallest = 0;
    int loop_n = 0;
    bool this_round = false;
    
    loop_profit_smallest=recent_profit;
   
    do {
        this_round = false;
    
    // if now we take the h airport out
   for(int h = 0; h < n; h++){
       
       
        int loop_profit = 0;
        int loop_benefit = 0;
        int loop_cost = 0;
       
       
    for(int i = 0; i < n; i++){
        
        if (i==h || build[i]==0)
            continue;
        
        if ( metrix_current_size[i]!=0){
                   
            for (int a = 0 ; a < metrix_current_size[i]; a++){
                
                if ( metrix_number[i][a]==h || build[metrix_number[i][a]]==0)
                    continue;
                
                loop_benefit+=metrix_benefit[i][a];
                    
                    }
                   
            }
       
        
        loop_cost+=cost[i];
        
    }
               
       
       loop_benefit=loop_benefit/2;
    
    
        loop_profit=loop_benefit-loop_cost;


       if (loop_profit > recent_profit){
           loop_n=h+1;
           loop_profit_smallest=loop_profit;
           recent_profit=loop_profit;
           this_round = true;
       }
       
   }
        if (this_round)
            build[loop_n-1]=0;
        else
            break;
   
        
    } while(true);
    
    
    int lastone=n;
    
    for(int i = n; i > 0; i--){
        if (build[i]==1)
            break;
        else
            lastone=lastone-1;
        }
    
    
    for(int i = 0; i < n; i++){
        
        
        if (i==lastone){
            if (build[i]==1)
                cout<<i+1<<';';
        }
        else{
            if (build[i]==1)
            cout<<i+1<<',';
            }
        }
    
    cout<<loop_profit_smallest;

    
    
    return 0;
}




*/

