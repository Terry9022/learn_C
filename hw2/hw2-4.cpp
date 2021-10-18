//
//  hw2-4.cpp
//  hw2
//
//  Created by Terry Lu on 2020/10/2.
//  Copyright © 2020 Terry Lu. All rights reserved.
//

#include <iostream>
using namespace std;


int main() {
    
    int n = 0;
    int first = 0;
    int second = 0;
    int third = 0;
    int fourth = 0;
    int firstBig,secondBig,thirdBig,fourthBig;
    int firstSmall,secondSmall,thirdSmall,fourthSmall;
    int lowest,middle1,middle2,highest;
    int a,b,c,d;
    int low1,high1,low2,high2;
    int Big=0, Small=0,ans=0;
    
    cin>>n;
   
    while ( ans != 6174){
        
    first=n/1000;
    second=n/100%10;
    third=n/10%10;
    fourth=n/1%10;
        
    a=first;
    b=second;
    c=third;
    d=fourth;
    
    if (a < b){
        low1 = a;
        high1 = b;}
    else {
        low1 = b;
        high1 = a;}

    if (c < d){
        low2 = c;
        high2 = d;}
    else {
        low2 = d;
        high2 = c;}

    if (low1 < low2){
        lowest = low1;
        middle1 = low2;}
    else {
        lowest = low2;
        middle1 = low1;}

    if (high1 > high2){
        highest = high1;
        middle2 = high2;}
    else {
        highest = high2;
        middle2 = high1;}

    if (middle1 < middle2){
        firstBig=highest;secondBig=middle2;thirdBig=middle1;fourthBig=lowest;
        firstSmall=lowest;secondSmall=middle1;thirdSmall=middle2;fourthSmall=highest;
    }
    
    else {
        firstBig=highest;secondBig=middle1;thirdBig=middle2;fourthBig=lowest;
        firstSmall=lowest;secondSmall=middle2;thirdSmall=middle1;fourthSmall=highest;
    }
        
    Big =firstBig*1000+secondBig*100+thirdBig*10+fourthBig;
    Small=firstSmall*1000+secondSmall*100+thirdSmall*10+fourthSmall;
    ans = Big - Small;
        if (ans!=6174){
            cout<<ans<<',';
            n = ans;}
        else {
            cout<<ans;
            n = ans;
        }
            
            
    }
    return 0;
}


