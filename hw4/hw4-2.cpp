//
//  hw4-2.cpp
//  hw4
//
//  Created by Terry Lu on 2020/10/18.
//  Copyright © 2020 Terry Lu. All rights reserved.



/*

#include <iostream>
#include <math.h>
using namespace std;

float MAPE(int windowSize , int periodCut , const int sales[]);



int main() {

   // Loading data
    
    int m = 0;
    const int MAX_PERIOD_CNT = 1000;
    int x[MAX_PERIOD_CNT] = {0};
    
    cin >> m;
    for(int i = 0; i < m; i++)
    cin >> x[i];
 
    int smallest_N=0;
    int smallest_Mape=999999999;
    int current_Mape = 0 ;
    
    for (int i=2;i<=6;i++){
    current_Mape = MAPE(i, m,x);
        if (current_Mape < smallest_Mape){
            smallest_Mape=current_Mape;
            smallest_N= i;
        }
    }
    
    
    
    cout<<smallest_N<<','<<smallest_Mape ;
        
    
    return 0 ;


}




float MAPE(int windowSize , int periodCut , const int sales[]){
    
    float total=0;
    float count=0;
    
    float current_avgDemand = 0;
      

    for(int i = windowSize; i <= periodCut-1; i++)
    {
       
        if (sales[i]==0)
            continue;
        
        else{
        
        count=count+1;
        int totalDemand = 0;
      
            
        for(int j = i - windowSize; j <= i-1 ; j++)
            totalDemand = totalDemand + sales[j];
            
            float avgDemand = static_cast<float>(totalDemand)/ static_cast<float>(windowSize);
            
            current_avgDemand  = fabs(sales[i]-avgDemand) / static_cast<float>(sales[i]);
        
            total=total+current_avgDemand ;
    
        }
        
    }
    
    
    
    float mape = 0 ;
    mape= total / (count);
    
    mape = static_cast<int>(mape *100) ;
    
    
    return mape;
    
}

*/
