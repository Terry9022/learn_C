//
//  main.cpp
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
 
    int* list = new int [n];
    int* list2 = new int [n];
    
    
    for (int i=0 ; i<n;i++){
        cin>>list[i];
        list2[i]=list[i];
        
    }
    
    int ans = 0;
    int tmp=0;
   
    for (int i=0 ; i<n;i++){
        
        
      for (int j=0 ; j<n;j++){
          
            
            tmp=list2[i];
            list2[i]=list2[j];
            list2[j]=tmp;
            
            int recent_len = 1;
            int max_len=0;
            
             
             
             for (int k=1 ; k<n ; k++){
                 
                 
                 
                 if (list2[k]>list2[k-1])
                     recent_len+=1;
                 
                 if (recent_len>max_len)
                     max_len=recent_len;
                 
                 if (list2[k]<=list2[k-1])
                     recent_len=1;
        
                     
             }
          
          
            tmp=list2[i];
            list2[i]=list2[j];
            list2[j]=tmp;
           
            if (max_len>ans)
            ans=max_len;
            
        }
    }
    
    
    
    
    
    
    cout<<ans;
   
    return 0;
}


*/
