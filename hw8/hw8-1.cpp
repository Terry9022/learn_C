//
//  hw8-1.cpp
//  hw8
//
//  Created by Terry Lu on 2020/12/20.
//  Copyright © 2020 Terry Lu. All rights reserved.
//

/*
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
 
// struct type

struct Card {
    
    char suit;
    int rank;
    bool isA(){
        
        if (rank == 1)
            return true;
        else
            return false;
        
    };
    
    
    bool init(char cardStr[]){
        
        if (cardStr[0] == ( 'S' ) )
            suit=cardStr[0];
        else if (cardStr[0] == ( 'D' ) )
            suit=cardStr[0];
        else if (cardStr[0] == ( 'H' ) )
            suit=cardStr[0];
        else if (cardStr[0] == ( 'C' ) )
            suit=cardStr[0];
        else
            return false;
        
        size_t length = strlen(cardStr);
        
        if (length ==2){
        
        if (cardStr[1] == 'A' )
            rank=1;
        if (cardStr[1] ==  '2')
            rank=2;
        if (cardStr[1] ==  '3' )
            rank=3;
        if (cardStr[1] ==  '4')
            rank=4;
        if (cardStr[1] ==  '5')
            rank=5;
        if (cardStr[1] ==  '6')
            rank=6;
        if (cardStr[1] ==  '7')
            rank=7;
        if (cardStr[1] ==  '8')
            rank=8;
        if (cardStr[1] ==  '9')
            rank=9;
        if (cardStr[1] ==  'J')
            rank=11;
        if (cardStr[1] ==  'Q')
            rank=12;
        if (cardStr[1] ==  'K')
            rank=13;
        
        }
        
        else if (length ==3){
            
            if (cardStr[1] ==  '1' && cardStr[2] ==  '0')
            rank=10;
        }
        
        else
            return false;
        
        
        
        return true;
        
        
    };
    
};

// self-defined function
int printHighScore(Card cardarray[]);



int main(){
     
    // input the data
    char str[80];
    char word[10][10] = {0};
    char delim[] = ",";
    int wordCnt = 0;
    cin>>str;
    
    char* start = strtok(str, delim);
    while (start != nullptr)
    {
       strcpy(word[wordCnt], start);
        wordCnt++;
       start = strtok(nullptr, delim);
    }
    
    // alogthrim
    
    // init Card
    Card cardArray[5];
    
    for (int i=0;i<5;i++){
        cardArray[i].init(word[i]);
    }
    
    
    
    for (int i=0;i<5;i++){
        cout<<word[i]<<',';
    }
    cout<<'\n';
    
    for (int i=0;i<5;i++){
        cout<<cardArray[i].rank<<',';
    }
    cout<<'\n';
   
    
    
    // use self-defined function
    int ans= 0;
    ans= printHighScore(cardArray);
    
    cout<<ans;
    
    return 0 ;
     
     
}
 



// self-defined function

int printHighScore(Card cardarray[]){
    
    int score=0;
    
    int rankArray[5]={0};
    int suitArray[5]={0};
    
    for (int i=0;i<5;i++){
        rankArray[i]=cardarray[i].rank;
        suitArray[i]=cardarray[i].suit;
    }
    
    std::sort(rankArray, rankArray+5);
    
    
    
    //同花順 五張撲克牌數字連續且花色相同   順 五張撲克牌數字連續
    if( ( rankArray[0]+1 == rankArray[1]  &&  rankArray[1]+1 == rankArray[2]  &&  rankArray[2]+1 == rankArray[3]  && rankArray[3]+1 == rankArray[4] )
     || (rankArray[0]==1 && rankArray[1]==10  && rankArray[2]==11  && rankArray[3]==12
          &&  rankArray[4]==13)
        )
    {
        if(suitArray[0]==suitArray[1] && suitArray[0]==suitArray[2]  && suitArray[0]==suitArray[3] && suitArray[0]==suitArray[4]){
            score=100;
            return score;
        }
        else{
             score=50;
            return score;
            }
    }
        
    //葫蘆 三張撲克牌數字相同，加上兩張撲克牌數字相同
    if ( (rankArray[0]==rankArray[1] && rankArray[1]==rankArray[2]  && rankArray[3]==rankArray[4]  )  || (rankArray[0]==rankArray[1] && rankArray[2]==rankArray[3]  && rankArray[3]==rankArray[4]  )
        ) {
        score=40;
        return score;
    }
    
    //同花 五張撲克牌花色相同
    if(suitArray[0]==suitArray[1] && suitArray[0]==suitArray[2]  && suitArray[0]==suitArray[3] && suitArray[0]==suitArray[4]){
        score=20;
        return score;
    }
    
    
    
    
    
    
    //一對 兩張撲克牌數字相同 有可能有兩對
    if  ( rankArray[0]==rankArray[1] && rankArray[2]==rankArray[3]){
        
        score+=10;
        if (rankArray[4]==1)
        score+=1;
        return score;
    }
    if  ( rankArray[0]==rankArray[1] && rankArray[3]==rankArray[4]){
        
        score+=10;
        if (rankArray[2]==1)
        score+=1;
        return score;
    }
        
    if  ( rankArray[1]==rankArray[2] && rankArray[3]==rankArray[4]  ){
        score+=10;
            if (rankArray[0]==1)
                score+=1;
        
        return score;
    }
    
    if ( rankArray[0]==rankArray[1] ){
        score+=5;
        rankArray[0]=-1;
        rankArray[1]=-1;
        
    }
    if ( rankArray[1]==rankArray[2] )
        {
            score+=5;
            rankArray[1]=-1;
            rankArray[2]=-1;
           
        }
      
    if ( rankArray[2]==rankArray[3] ){
        score+=5;
        rankArray[2]=-1;
        rankArray[3]=-1;
        
    }
        
    if ( rankArray[3]==rankArray[4] )
        {
            score+=5;
            rankArray[3]=-1;
            rankArray[4]=-1;
            
        }
      
    
    //A 一張撲克牌點數為 A
    
    for (int i=0;i<5;i++){
        if (rankArray[i]==1)
            score+=1;
        
    }
    
   
    
        
    return score;
}


*/
