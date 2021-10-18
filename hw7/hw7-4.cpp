//
//  hw7-4.cpp
//  hw7
//
//  Created by Terry Lu on 2020/12/6.
//  Copyright © 2020 Terry Lu. All rights reserved.
//


#include <iostream>
#include <cstring>
using namespace std;

void clean(char *p);
bool same(char p[], char q[]);

int main() {

    
    //load the data
    
    int n =0;
    int m =0;
    
    cin>>n>>m;
    
    
    int* cost = new int[n];
    int* build = new int[n];


    
    // correct city name array
       char** city = new char* [n];
    for(int i = 0; i < n; i++){
        city[i]=new char[10];
        cin>> city[i];
    }
    
    for(int i = 0; i < n; i++){
        
        cin >> cost[i];
        build[i]=1;
       
    }

    //benefit 2d array matrix
    int matrix[100][100]={0};
    
    
    // read the benefit
    // benefit into metrix
   
    
    
    for(int i = 0; i < m; i++){
        
        char* first = new char[10];
        char* second = new char[10];
    
        cin>>first;
        cin>>second;
        
        //clean( first);
       // clean( second);
        
        int first_airport = 0;
        int second_airport = 0;
        int their_benefit = 0;
        
        cin>>their_benefit;
        
        for(int bb = 0; bb < n; bb++){
            if  (strcmp(first,city[bb] ) == 0){
                first_airport=bb;
            
            }
            if (strcmp(second,city[bb] ) == 0)
                second_airport=bb;
        }
        
        
        matrix[first_airport][second_airport]=their_benefit;
        matrix[second_airport][first_airport]=their_benefit;
     
      //  delete [] first;
      //  delete [] second;
     // first = nullptr;
      //second = nullptr;
        
        
    }
    
    
    
     // algorithm
       
       // first round profit counting
       int recent_profit =0;
       int sum_benefit=0;
       int sum_cost=0;
      
       for(int i = 0; i < n; i++){
           for (int j = 0 ; j < n; j++){
                  sum_benefit+=matrix[i][j];
                  }
              }
       sum_benefit=sum_benefit/2;
       
       
       for(int i = 0; i < n; i++)
           sum_cost+=cost[i];
       
       
       recent_profit=sum_benefit-sum_cost;
       
       
       // after first round, we use algorithm to find the one we want to discard.
       
       
       
       int loop_profit_smallest = 0;
       int loop_n = 0;
       bool this_round = false;
       
       loop_profit_smallest=recent_profit;
      
       do {
           this_round = false;
       
      for(int h = 0; h < n; h++){
          
          
           int loop_profit = 0;
           int loop_benefit = 0;
           int loop_cost = 0;
          
          
       for(int i = 0; i < n; i++){
           if (i==h || build[i]==0)
               continue;
           
           for (int j = 0 ; j < n; j++){
               if (j==h|| build[j]==0)
                   continue;
                  loop_benefit+=matrix[i][j];
                  }
              }
          
          loop_benefit=loop_benefit/2;
       
       
          for(int i = 0; i < n; i++){
           if (i==h || build[i]==0)
           continue;
              
           loop_cost+=cost[i];}
       
       
           loop_profit=loop_benefit-loop_cost;


          if (loop_profit>recent_profit){
              loop_n=h+1;
              loop_profit_smallest=loop_profit;
              recent_profit=loop_profit;
              this_round = true;
          }
          
      }
           if (this_round){
               build[loop_n-1]=0;}
           else{break;}
       
       } while(true);
       
    
    
    
    cout<<loop_profit_smallest;

    for(int i = 0; i < n; i++)
        cout<<city[i]<<',';
    
    
    for(int i = 0; i < n; i++){
      for (int j = 0 ; j < n ; j++){
         cout<<matrix[i][j];
      }
        
    }
        
    

    
    return 0;
}




void clean(char* p) {
    
    double n = strlen(p);
    int count = 0;
    
    char* temp = new char[n];
    
    for(int i = 0; i < n; i++)
        if (p[i]!=' '){
        temp[count] =  static_cast<char>(toupper(p[i]));
            count+=1;
        }
    
    for(int i = 0; i < 3; i++)
            p[i] = temp[i];
    
    p[3]='\0';
    delete [] temp;
        }


bool same(char p[], char q[]){
    
    bool ans = true;
    
    for(int i = 0; i < 3; i++){
        if (p[i]!=q[i])
            ans = false;
    }
    
    
    return ans;
    
}

