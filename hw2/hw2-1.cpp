//
//  hw2-1.cpp
//  hw2
//
//  Created by Terry Lu on 2020/10/1.
//  Copyright © 2020 Terry Lu. All rights reserved.
//

/*
#include <iostream>
using namespace std;

int main() {
    
    int n = 0;
    int input = 0;
    int count = 0;
    int index = 1;
    int maxLength = 0;
    int startIndex = 0;
    cin>>n;

    for (int i =0 ; i < n; i++ ){
        cin>>input;
        if (input>0){
            if (index == 0){
                index = i + 1;
            }
            count = count + 1;
            
            if (count > maxLength){
                maxLength = count;
                startIndex = index;
                
            }
            
        }
        else if (input<=0){
            index = 0;
            count = 0;
            
        }
    }
    if (maxLength > 0){
    cout<<maxLength<<','<< startIndex;
    }
    else {
        cout<<0;
    }
    return 0;
}
*/
