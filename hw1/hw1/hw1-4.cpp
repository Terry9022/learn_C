//
//  hw1-4.cpp
//  hw1
//
//  Created by Terry Lu on 2020/9/27.
//  Copyright © 2020 Terry Lu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    float input = 0;
    int count = 0;
    int output = 0;
    
    while(true){
        
        cin>>input;
        
        if (input > 37){
            break;
        }
        
        if (count>0){
               cout<<",";
           }
        
        output = input;
        cout<<output;
        count+=1;
        
        }
    return 0;
}
