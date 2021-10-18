//
//  Q2.cpp
//  quiz1
//
//  Created by Terry Lu on 2020/10/13.
//  Copyright © 2020 Terry Lu. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    int n = 0;
    int m = 0;
    int inputx = 0;
    int inputy = 0;
    int minx=0;
    int miny=0;
    int inner=0;
   
    cin>>n>>m;
    
   int* arrayx = new int[n];
   int* arrayy = new int[m];
    
    
   for (int i =0 ; i < n; i++){
       cin>>inputx;
       arrayx[i]=inputx;
   }
    
    
    for (int i =0 ; i < m; i++){
        cin>>inputy;
        arrayy[i]=inputy;
    }
     
    minx= *std::min_element(arrayx,arrayx+n);
    miny= *std::min_element(arrayy,arrayy+m);
    
    
    if (n==m){
        
        for (int i =0 ; i < n; i++){
            inner=inner+arrayx[i]*arrayy[i];
             }
          
        cout<<inner;
        
    }
    
    else if (n<m)
        cout<<minx;
    
    else
        cout<<miny;
    
    
    
    return 0 ;
}

