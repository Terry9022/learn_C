//
//  hw3-1.cpp
//  hw3
//
//  Created by Terry Lu on 2020/10/9.
//  Copyright © 2020 Terry Lu. All rights reserved.
//
/*
#include <iostream>
using namespace std;

int main() {
    
    int n = 0;
    int x = 0;
    int inputTNow=0;
    int inputRNow=0;
    int inputRLastOne=0;
    int ansPrice = 0;
    int ansTicket = 0;
    int ansPriceLowest= 0;
    long recentPrice  = 999999999999999;
  
    cin>>n>>x;
    
 
    int* price = new int[n+1];
    int* ticket = new int[n+1];
    for (int i =0 ; i < n; i++){
        cin>>inputTNow>>inputRNow;
        ticket[i]=inputTNow;
        price[i]=inputRNow;
    }
    cin>>inputRLastOne;
    price[n]=inputRLastOne;
    ticket[n]=x;

    

    for (int i=0 ; i<n+1 ;i++){
        if (i==0){
            if (x<=ticket[i]){
                ansPrice= ansPrice+price[i]*(x) ;
            if (ansPrice<=recentPrice){
                       recentPrice=ansPrice;
                       ansPriceLowest=ansPrice;
                       ansTicket = x;
            }}
            else{
            ansPrice=ansPrice+ price[i]*ticket[i];
            if (ticket[i]>=x && ansPrice<=recentPrice){
                recentPrice=ansPrice;
                ansPriceLowest=ansPrice;
                ansTicket = ticket[i];
            }}
                
            }
            
        
        else if (i<n){
                if (ticket[i-1]<=x && x<=ticket[i]){
                    ansPrice= ansPrice+price[i]* (x-ticket[i-1]) ;
                if (ansPrice<=recentPrice){
                           recentPrice=ansPrice;
                           ansPriceLowest=ansPrice;
                           ansTicket = x;
                       }
                ansPrice=ansPrice+price[i]*(ticket[i]-x);
                if (ansPrice<=recentPrice){
                    recentPrice=ansPrice;
                    ansPriceLowest=ansPrice;
                    ansTicket = ticket[i];
                }
              
            }
            else {ansPrice= ansPrice+price[i]*(ticket[i] - ticket[i-1]) ;
                if (ticket[i]>=x && ansPrice<=recentPrice){
                    recentPrice=ansPrice;
                    ansPriceLowest=ansPrice;
                    ansTicket = ticket[i];
                }
            }
        
        }
        else if (i==n && x >= ticket[n-1]){
            ansPrice= ansPrice+price[i]*(ticket[i]-ticket[i-1]) ;
            if (ticket[i]>=x && ansPrice<=recentPrice){
                recentPrice=ansPrice;
                ansPriceLowest=ansPrice;
                ansTicket = ticket[i];
            }
        }
    
    

    }

    
    cout<<ansTicket<<','<<ansPriceLowest;
    
    return 0 ;
}


*/
