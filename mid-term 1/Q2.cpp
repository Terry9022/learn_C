//
//  Q2.cpp
//  mid-term 1
//
//  Created by Terry Lu on 2020/10/20.
//  Copyright © 2020 Terry Lu. All rights reserved.
//
/*
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
 
    int n =0;
    int r =0;
    cin>>n>>r;
   
    int max_people = 0;
    
    
    int* people_count = new int[n+(r*2)];
    for (int i=0 ; i<n+(r*2);i++){
        if (i<r || i > n+r-1)
            people_count[i]=0;
        else
            cin>>people_count[i];
    }
    
    for (int i=r ; i<n+r ;i++){
        int current_people =0;
        
        for (int j=-r ; j<=r ; j++){
        
            current_people+=people_count[i+j];
            
    }
    
        if  (current_people > max_people)
            max_people=current_people;
        
    }
    
    
    
    cout<<max_people;
    
    
    return 0;
}
*/
