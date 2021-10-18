//
//  hw9-3.cpp
//  hw9
//
//  Created by Terry Lu on 2020/12/27.
//  Copyright © 2020 Terry Lu. All rights reserved.
//


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
 
int n =0;
int m =0;


// class Option

class Option {
    
    
public:
    
    int id;
    int value[10]={0};
    
    void init(int arr[]){
        id=arr[0];
     for (int j=0;j<m;j++){
            value[j]=arr[j+1];
        }
        
    }
    
    bool isDominating(Option b){
        
        bool atleast=false;
        
        for (int j=0;j<m;j++){
            
            if (value[j]<b.value[j])
                atleast=true;
            else if (value[j]==b.value[j])
                continue;
            else
                return false;
        }
        
        if (atleast)
            return true;
        else
            return false;
            
    };
    
    
    bool isBefore(Option b){
        
        if (id<b.id)
            return true;
        else
            return false;
    };
    
};
    

bool mycompare(Option c1, Option c2){
   return c1.id < c2.id;
}


int main(){
    
    // input the data
    
    cin>>n>>m;
    
    Option optionArray[100];
        
    for (int i=0;i<n;i++){
        
        int* tmp = new int [m+1];
        
        for (int j=0;j<m+1;j++){
            cin>>tmp[j];
        }
        
        Option tempOption;
        tempOption.init(tmp);
        
        optionArray[i]=tempOption;
        
        delete[] tmp;
        tmp=nullptr;
        
       }
    
   
    
    
    // alogthrim
    
    Option ans[100];
    int ansIndex=0;
    
    for (int i=0;i<n;i++){
        
        bool notBetter = true;
        
        for (int j=0;j<n;j++){
            
            if (i==j)
                continue;
                
            
                
          if  (optionArray[j].isDominating(optionArray[i]))
              notBetter=false;
        }
        
        if (notBetter){
            ans[ansIndex]=optionArray[i];
            ansIndex+=1;
        }
    }
            
    std::sort(ans,ans+ansIndex,mycompare);
    
    for (int i=0;i<ansIndex;i++){
        for (int j=0;j<m;j++){
            if (j==m-1)
                cout<<ans[i].value[j];
            else
                cout<<ans[i].value[j]<<',';
        }
        if (i!=ansIndex-1)
            cout<<';';
    }
    
    return 0 ;
     
     
}
 


