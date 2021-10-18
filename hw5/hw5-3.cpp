//
//  hw5-3.cpp
//  hw5
//
//  Created by Terry Lu on 2020/11/2.
//  Copyright © 2020 Terry Lu. All rights reserved.
//


#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

void connect_subway(int s1,int s2);

int m =0;
int n =0;
int s =0;
int L =0;
int benefit_people=0;
int possible[50][2] = {0};
int want[50][2] = {0};
int matrix[101][101] = {0};
int matrix_benefit_subway_ornot[110][110] = {0};
int matrix_benefit_station_ornot[110][110] = {0};
int station[20][2] = {0};





int main() {
 
    int people_benefit_subway=0;
    int people_benefit_station=0;

   
    //load the data
    
    cin>>m>>n>>s>>L;
   
    
    for (int i=0 ; i<=m ; i++){
        for (int j=0 ; j<=n ; j++){

            cin>>matrix[i][j];
           }
        }
    
    
    for (int i=0 ; i<s ; i++){
         for (int j=0 ; j<2 ; j++){
             cin>>station[i][j];
            }
         }
    
    
    
    for (int i=0 ; i<s ; i++){
         for (int j=0 ; j<s ; j++){
             
             if (station[i][0]==station[j][0] && i!=j){
                
                 possible.insert({i,j});
                 
                 
             }
            }
         }
    
     
    //algorithm
    
    

    
    return 0;
}






void connect_subway(int s1,int s2){
    
    int first_station_x = station[s1-1][0];
    int first_station_y = station[s1-1][1];
    int second_station_x = station[s2-1][0];
    int second_station_y = station[s2-1][1];
    int connect_x[2] = {0};
    int connect_y[2] = {0};
    
    if (first_station_x == second_station_x){
        
        connect_y[0]=first_station_y;
        connect_y[1]=second_station_y;
        std::sort(connect_y, connect_y+2);
        
       
    
    
    else if(first_station_y == second_station_y){
        
        connect_x[0]=first_station_x;
        connect_x[1]=second_station_x;
        std::sort(connect_x, connect_x+2);
        
    }
}





