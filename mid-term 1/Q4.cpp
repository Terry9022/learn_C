//
//  Q4.cpp
//  mid-term 1
//
//  Created by Terry Lu on 2020/10/20.
//  Copyright © 2020 Terry Lu. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

void connect_subway(int s1,int s2);
void connect_station(int x,int y);

int m =0;
int n =0;
int r =0;
int s =0;
int t =0;
int matrix[101][101] = {0};
int matrix_benefit_subway_ornot[110][110] = {0};
int matrix_benefit_station_ornot[110][110] = {0};
int station[20][2] = {0};
int subway[100][2] = {0};



int main() {
 
    int people_benefit_subway=0;
    int people_benefit_station=0;
    //load the data
    
    cin>>m>>n>>r>>s>>t;
   
    
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
    
    
    for (int i=0 ; i<t ; i++){
         for (int j=0 ; j<2 ; j++){
             cin>>subway[i][j];
            }
         }
     
    //algorithm
    
     for (int i=0 ; i<t ; i++){
         connect_subway( subway[i][0],subway[i][1]);
     }
    
    
    
    for (int i=0 ; i<s ; i++){
        connect_station(station[i][0],station[i][1]);
    }
    
    for (int i=0 ; i<=m ; i++){
            for (int j=0 ; j<=n ; j++){

                if (matrix_benefit_subway_ornot[i][j]==1){
                    
                    people_benefit_subway+=matrix[i][j];
                    
                }
                
                if (matrix_benefit_station_ornot[i][j]==1){
                    
                    people_benefit_station+=matrix[i][j];
                    
                }
                    
               }
            }
    
    
   
    cout<<people_benefit_station<<','<<people_benefit_subway;
    
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
        
        for (int i = connect_y[0] ; i<=connect_y[1] ; i++){
            
            matrix_benefit_subway_ornot[first_station_x][i]=1;
        }
    }
    
    
    else if(first_station_y == second_station_y){
        
        connect_x[0]=first_station_x;
        connect_x[1]=second_station_x;
        std::sort(connect_x, connect_x+2);
        
        for (int i = connect_x[0] ; i<=connect_x[1] ; i++){
            
            matrix_benefit_subway_ornot[i][first_station_y]=1;
        }
    }
    
}


void connect_station(int x,int y){
    
    int left_down_x= std::max(x-r,0);
    int left_down_y= std::max(y-r,0);
    int left_up_x =  std::max(x-r,0);
    int left_up_y = y+r;
    int right_up_x= x+r;
    int right_up_y= y+r;
    int right_down_x = x+r;
    int right_down_y = std::max(y-r,0);
    
    
    
     for (int i=left_down_x ; i<=right_up_x ; i++){
           for (int j=left_down_y ; j<=right_up_y ; j++){

               matrix_benefit_station_ornot[i][j]=1;
              }
           }
    
}




