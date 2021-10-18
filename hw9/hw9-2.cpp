//
//  hw9-2.cpp
//  hw9
//
//  Created by Terry Lu on 2020/12/27.
//  Copyright © 2020 Terry Lu. All rights reserved.
//

/*
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
 


// class Card

class Card {
    
public:
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




// class CardStack
class CardStack {
    
public:
    
    Card cards[52];
    int cardCnt;
    void addCards(Card c[],int cnt){
        
        for (int i=0;i<cnt;i++){
            cards[i]=c[i];
        }
        
        cardCnt=cnt;
    };
    
    
};



int main(){
     
  
    // init Card
    Card cardArray[52];
    
    
    
    // input the data
    char str[800];
    char word[60][10] = {0};
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
    
    
    
    for (int i=0;i<wordCnt;i++){
        cardArray[i].init(word[i]);
        }
        
    
     char words[52][10]  = {
            "SA", "S2", "S3", "S4","S5","S6","S7","S8","S9","S10","SJ","SQ","SK",
            "HA", "H2", "H3", "H4","H5","H6","H7","H8","H9","H10","HJ","HQ","HK",
            "DA", "D2", "D3", "D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK",
            "CA", "C2", "C3", "C4","C5","C6","C7","C8","C9","C10","CJ","CQ","CK",
        };
        
        // init Card
    Card SForPlay[13];
    Card HForPlay[13];
    Card DForPlay[13];
    Card CForPlay[13];
          
          for (int i=0;i<13;i++){
              SForPlay[i].init(words[i]);
              HForPlay[i].init(words[i+13]);
              DForPlay[i].init(words[i+26]);
              CForPlay[i].init(words[i+39]);
          }
    
     int S = 0;
     int H = 0;
     int D = 0;
     int C = 0;
    
    
    // alogthrim
    
    CardStack cardstack;
    cardstack.addCards(cardArray, wordCnt);
     
     for (int i=0;i<=wordCnt;i++){
         
         
         if (cardstack.cards[i].suit=='S' && cardstack.cards[i].rank==SForPlay[S].rank){
             S+=1;
         }
         
         if (cardstack.cards[i].suit=='H' && cardstack.cards[i].rank==HForPlay[H].rank){
             H+=1;
         }
         if (cardstack.cards[i].suit=='D' && cardstack.cards[i].rank==DForPlay[D].rank){
             D+=1;
         }
         if (cardstack.cards[i].suit=='C' && cardstack.cards[i].rank==CForPlay[C].rank){
             C+=1;
         }
       
         
            }
    
    cout<<S<<','<<H<<','<<D<<','<<C;
    
    
    
    return 0 ;
     
     
}
 
*/

