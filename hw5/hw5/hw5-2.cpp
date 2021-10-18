//
//  hw5-2.cpp
//  hw5
//
//  Created by Terry Lu on 2020/11/2.
//  Copyright © 2020 Terry Lu. All rights reserved.
//
/*
#include <iostream>
#include <algorithm>
using namespace std;

int countpeople(int x,int y);

int n =0;
int m =0;
int r =0;
int matrix[2001][2001] = {0};


int main() {
 
   
    //load the data
    
    cin>>n>>m>>r;
   
    
    for (int i=0 ; i<=m ; i++){
        for (int j=0 ; j<=n ; j++){

            cin>>matrix[j][i];
           }
        }
    
   
    //algorithm
    int current_people=0;
    int max_people=0;
    
    for (int i=0 ; i<=m ; i++){
        for (int j=0 ; j<=n ; j++){
            
            current_people= countpeople(j,i);
            
            if (current_people > max_people)
                max_people=current_people;
       }
    }
    
    
    cout<<max_people;
   
    
    return 0;
}






int countpeople(int x,int y){
    
    int people =0;
    int x_index = 0;
    int y_index = 0;
    
    
    // 菱形中的下方三角形
    for (int j = 0 ;  j<=  r ; j++ ){
        y_index = y-r+j;
        if (y_index < 0 ){continue;}
        for (int i = x-j ; i <=  x+j ; i++){
            x_index = i ;
            if (x_index < 0 ){continue;}
            x_index = max( x_index , 0);
            people+=matrix[x_index][y_index];
        }
        
    }
    // 菱形中的上方三角形
    for (int j = 0 ;  j< r ; j++){
        y_index = y+r-j;
        if (y_index < 0 ){continue;}
        for (int i =x-j ; i <=  x +j ; i++){
            x_index = i;
            if (x_index < 0 ){continue;}
            people+=matrix[x_index][ y_index];
            
        }
    }
    
    
    
    return people ;

    
    
    
}


*/
