//
//  hw6-1.cpp
//  hw6
//
//  Created by Terry Lu on 2020/11/15.
//  Copyright © 2020 Terry Lu. All rights reserved.
//
/*
bool search_circle(int num_see);
 
#include <iostream>
#include <algorithm>
using namespace std;
 
 
 
int n=0;
int m=0;
int matrix[100][100]={0};
int num_point = 0;
int* circle_check = new int[num_point];
int ans = 0;
 
 
 
 
int main() {
     
    //load the data
    cin>>n>>m;
     
    for (int i=0;i<m;i++){
        int start =0;
        int end=0;
         
        cin>>start>>end;
         
        matrix[start-1][end-1]=1;
         
    }
     
    cin>>num_point;
     
     
    for (int i=0;i<num_point;i++){
 
        int input = 0;
        cin>>input;
        circle_check[i]=input;
    }
     
    
    // algorithm
    
    for (int i=0;i<num_point;i++){
 
        bool ans2=search_circle(circle_check[i]);
         
    }
     
     
        cout<<ans;
    
     
     
     
     
    return 0 ;
     
     
}
 
 
 
bool search_circle(int num_see){
     
    
    int current_num = num_see;
    
    
     
    int current_find[100]= {0};
    int current_count = 0;
    bool find = false;
     
    
    for (int i=0;i<n;i++){
         
        if (matrix[current_num-1][i]==1){
            current_count+=1;
            current_find[current_count]=i+1;
             
        }
    }
     
    
     
        
    for (int x=0;x<current_count;x++){
        for (int j=0;j<num_point;j++){
             
            if (current_find[x]==circle_check[j]){
                ans=1;
                return true;
            }
        }
  
    }
         
    return false;
         
     
}
*/
