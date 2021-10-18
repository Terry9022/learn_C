//
//  hw8-3.cpp
//  hw8
//
//  Created by Terry Lu on 2020/12/21.
//  Copyright © 2020 Terry Lu. All rights reserved.
//


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
 


// struct Card type

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


// struct Deck type
struct Deck {
    
    Card* cards;
    int cardCnt;
    void addCard(Card c[]){
        cards=c;
    };
    
    int getPoint(){
        
        return printHighScore(cards);
    };
};


// construct the randomizer

struct Randomizer
{
  int a;
  int b;
  int c;
  int cur;
  int rand();
};
int Randomizer::rand()
{
  cur = (a * cur + b) % c;
  return cur;
}


int main(){
     
    
    int s, a, b, c;
    cin>>s>>a>>b>>c;
    
    Randomizer r1 = {a, b, c, s}; // this is exactly following the C++ syntax
    
    char word[52][10]  = {
        "SA", "S2", "S3", "S4","S5","S6","S7","S8","S9","S10","SJ","SQ","SK",
        "HA", "H2", "H3", "H4","H5","H6","H7","H8","H9","H10","HJ","HQ","HK",
        "DA", "D2", "D3", "D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK",
        "DA", "D2", "D3", "D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK",
    };
    
    // init Card
      Card cardArray[52];
      
      for (int i=0;i<52;i++){
          cardArray[i].init(word[i]);
      }
    
    
    for (int i=0;i<20;i++){
        int r = r1.rand() % 52;
        Card swap_tmp = cardArray[r] ;
        cardArray[r] = cardArray[i] ;
        cardArray[i] = swap_tmp ;
    }
    
    
    // alogthrim
    
    int maxAns=0;
    int winner=0;
    
    for (int j=0;j<4;j++){
   
    Card cardArrayForPlayer[5];
    
    for (int i=0;i<5;i++){
      
        int distribution_index = i*4+j;
        cardArrayForPlayer[i]= cardArray[distribution_index];
    }
    
    
     // use self-defined type and method
    Deck deck;
    deck.addCard(cardArrayForPlayer);
    
    int ans= 0;
    ans= deck.getPoint();
        
    if (ans>maxAns){
        maxAns=ans;
        winner=j+1;
        }
    }
    
    cout<<winner<<','<<maxAns;
    
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





