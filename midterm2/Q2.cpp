//
//  Q2.cpp
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
    
    int n =0;
    
    cin>>n;
 
    int** metrix = new int*[n];
    for(int i = 0; i < n; ++i)
        metrix[i] = new int[8];
    
    
    for (int i=0 ; i<n;i++){
        
        for (int j=0 ; j<8;j++){
            
            cin>>metrix[i][j];
            
        }
        
    }
    
    
    int ans=0;
    
    
    for (int i=0 ; i<n;i++){
         
         int x1=metrix[i][0];
         int x2=metrix[i][1];
         int y1=metrix[i][6];
         int y2=metrix[i][5];
         
         
         for (int j=0 ; j<i;j++){
             
             int x1_2=metrix[j][0];
             int x2_2=metrix[j][1];
             int y1_2=metrix[j][6];
             int y2_2=metrix[j][5];
             
             
             
             
    if(  (x1_2<x1 && x1 < x2_2)  || (x1_2<x2 && x2 <x2_2)  )
     if(  (y1_2<y1 && y1 < y2_2)  || (y1_2<y2 && y2 <y2_2)  )
      ans+=1;
             
             
  if(  (x1_2==x1 )  || (x2 == x2_2)  )
   if(  (y1_2<y1 && y1 < y2_2)  || (y1_2<y2 && y2 <y2_2)  )
   ans+=1;
             
             
   if(  (x1_2<x1 && x1 < x2_2)  || (x1_2<x2 && x2 <x2_2)  )
    if(  (y1_2==y1 )  || ( y2 == y2_2)  )
    ans+=1;
             
             
    if(  (x1_2==x1 )  || (x2 == x2_2)  )
    if(  (y1_2==y1 )  || ( y2 == y2_2)  )
     ans+=1;
         }
         
         
         
     }
  
    
    
    
    cout<<ans;
    
    
   
    return 0;
}

*/
