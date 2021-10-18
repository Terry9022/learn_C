

#include <iostream>
using namespace std;

int main() {
    
    int n1 = 0;
    int x1 = 0;
    int n2 = 0;
    int x2 = 0;
    int d = 0;
    int m = 0;
    int inputTNow=0;
    int inputRNow=0;
    int inputRLastOne=0;
    
    int ansPrice1 = 0;
    int ansTicket1 = 0;
    int ansPriceLowest1= 0;
    long recentPrice1  = 999999999999999;
    
    int ansPrice2 = 0;
    int ansTicket2 = 0;
    int ansPriceLowest2 = 0;
    long recentPrice2  = 999999999999999;
    
    int ansPriceLowestTotal=0;
  
    
    cin>>n1>>n2>>x1>>x2>>d>>m;
    
 
    int* price1 = new int[n1+1];
    int* ticket1 = new int[n1+1];
    for (int i =0 ; i < n1; i++){
        cin>>inputTNow>>inputRNow;
        ticket1[i]=inputTNow;
        price1[i]=inputRNow;
    }
    cin>>inputRLastOne;
    price1[n1]=inputRLastOne;
    ticket1[n1]=x1;

    
    int* price2 = new int[n2+1];
    int* ticket2 = new int[n2+1];
    for (int i =0 ; i < n2; i++){
        cin>>inputTNow>>inputRNow;
        ticket2[i]=inputTNow;
        price2[i]=inputRNow;
    }
    cin>>inputRLastOne;
    price2[n2]=inputRLastOne;
    ticket2[n2]=x2;
    
    
    
    
    

    for (int i=0 ; i<n1+1 ;i++){
        if (i==0){
            if (x1<=ticket1[i]){
                ansPrice1= ansPrice1+price1[i]*(x1) ;
            if (ansPrice1<=recentPrice1){
                       recentPrice1=ansPrice1;
                       ansPriceLowest1=ansPrice1;
                       ansTicket1 = x1;
            }}
            else{
            ansPrice1=ansPrice1+ price1[i]*ticket1[i];
            if (ticket1[i]>=x1 && ansPrice1<=recentPrice1){
                recentPrice1=ansPrice1;
                ansPriceLowest1=ansPrice1;
                ansTicket1 = ticket1[i];
            }}
                
            }
            
        
        else if (i<n1){
                if (ticket1[i-1]<=x1 && x1<=ticket1[i]){
                    ansPrice1= ansPrice1+price1[i]* (x1-ticket1[i-1]) ;
                if (ansPrice1<=recentPrice1){
                           recentPrice1=ansPrice1;
                           ansPriceLowest1=ansPrice1;
                           ansTicket1 = x1;
                       }
                ansPrice1=ansPrice1+price1[i]*(ticket1[i]-x1);
                if (ansPrice1<=recentPrice1){
                    recentPrice1=ansPrice1;
                    ansPriceLowest1=ansPrice1;
                    ansTicket1 = ticket1[i];
                }
              
            }
            else {ansPrice1= ansPrice1+price1[i]*(ticket1[i] - ticket1[i-1]) ;
                if (ticket1[i]>=x1 && ansPrice1<=recentPrice1){
                    recentPrice1=ansPrice1;
                    ansPriceLowest1=ansPrice1;
                    ansTicket1 = ticket1[i];
                }
            }
        
        }
        else if (i==n1 && x1 >= ticket1[n1-1]){
            ansPrice1= ansPrice1+price1[i]*(ticket1[i]-ticket1[i-1]) ;
            if (ticket1[i]>=x1 && ansPrice1<=recentPrice1){
                recentPrice1=ansPrice1;
                ansPriceLowest1=ansPrice1;
                ansTicket1 = ticket1[i];
            }
        }


    }

    
    for (int i=0 ; i<n2+1 ;i++){
        if (i==0){
            if (x2<=ticket2[i]){
                ansPrice2= ansPrice2+price2[i]*(x2) ;
            if (ansPrice2<=recentPrice2){
                       recentPrice2=ansPrice2;
                       ansPriceLowest2=ansPrice2;
                       ansTicket2 = x2;
            }}
            else{
            ansPrice2=ansPrice2+ price2[i]*ticket2[i];
            if (ticket2[i]>=x2 && ansPrice2<=recentPrice2){
                recentPrice2=ansPrice2;
                ansPriceLowest2=ansPrice2;
                ansTicket2 = ticket2[i];
            }}
                
            }
            
        
        else if (i<n2){
                if (ticket2[i-1]<=x2 && x2<=ticket2[i]){
                    ansPrice2= ansPrice2+price2[i]* (x2-ticket2[i-1]) ;
                if (ansPrice2<=recentPrice2){
                           recentPrice2=ansPrice2;
                           ansPriceLowest2=ansPrice2;
                           ansTicket2 = x2;
                       }
                ansPrice2=ansPrice2+price2[i]*(ticket2[i]-x2);
                if (ansPrice2<=recentPrice2){
                    recentPrice2=ansPrice2;
                    ansPriceLowest2=ansPrice2;
                    ansTicket2 = ticket2[i];
                }
              
            }
            else {ansPrice2= ansPrice2+price2[i]*(ticket2[i] - ticket2[i-1]) ;
                if (ticket2[i]>=x2 && ansPrice2<=recentPrice2){
                    recentPrice2=ansPrice2;
                    ansPriceLowest2=ansPrice2;
                    ansTicket2 = ticket2[i];
                }
            }
        
        }
        else if (i==n2 && x2 >= ticket2[n2-1]){
            ansPrice2= ansPrice2+price2[i]*(ticket2[i]-ticket2[i-1]) ;
            if (ticket2[i]>=x2 && ansPrice2<=recentPrice2){
                recentPrice2=ansPrice2;
                ansPriceLowest2=ansPrice2;
                ansTicket2 = ticket2[i];
            }
        }
      

    }
    
    
    
    
    
      
    int sum1=0;
    int count1=0;
    int totalPrice1[10000 ] = {0};
    for (int i=0 ; i<10000  ;i++){
                  
        sum1=sum1+price1[count1];
        totalPrice1[i]=sum1;
            if (i+1 == ticket1[count1]){
                if (count1<n1)
                      count1=count1+1;
                  }
              }
              
              
    int sum2=0;
    int count2=0;
    int totalPrice2[10000 ] = {0};
    for (int i=0 ; i<10000  ;i++){
                    
        sum2=sum2+price2[count2];
        totalPrice2[i]=sum2;
            if (i+1 == ticket2[count2]){
                if (count2<n2)
                    count2=count2+1;
                    }
                }
              
              
              
    int countmax1=0;
    int pricemax1=0;
    for (int i=0 ; i<10000  ;i++){
                    
    if (d>=totalPrice1[i]){
            countmax1=countmax1+1;
            pricemax1=totalPrice1[i];
            if (countmax1==x1)
                break;
            }
        }
                
                
    int countmax2=0;
    int pricemax2=0;
    for (int i=0 ; i<10000  ;i++){
                    
        if (d>=totalPrice2[i]){
            countmax2=countmax2+1;
            pricemax2=totalPrice2[i];
            if (countmax2==x2)
                break;
        }
                }
    
    
    
    int sumPriceFor0=0;
    int ansSumPriceFor0=0;
    int sumTicketFor0=0;
    int recentsumTicketFor0=0;
    int recentmutiTicketFor0=0;
    int mutiTicketFor0 = 0;
    int countmax1For0=0;
    int pricemax1For0=0;
    int countmax2For0=0;
    int pricemax2For0=0;

  
    
    
    for (int i=0 ; i<10000 ;i++){
        for (int j=0 ; j<10000 ;j++){
            sumPriceFor0=totalPrice1[i]+totalPrice2[j];
            if (sumPriceFor0 <=d & i+1<=x1 & j+1<=x2){
                sumTicketFor0=i+j+2;
                mutiTicketFor0=(i+1)*(j+1);
                if (sumTicketFor0 > recentsumTicketFor0 & i+1<=x1 & j+1<=x2 ){
                    recentsumTicketFor0=sumTicketFor0;
                    countmax1For0=i+1;
                    countmax2For0=j+1;
                    ansSumPriceFor0=sumPriceFor0;}
                else if(sumTicketFor0 == recentsumTicketFor0 & i+1<=x1 & j+1<=x2){
                        if(mutiTicketFor0 >= recentmutiTicketFor0 ){
                        recentmutiTicketFor0 =mutiTicketFor0;
                        countmax1For0=i+1;
                        countmax2For0=j+1;
                        ansSumPriceFor0=sumPriceFor0;
                    }
                    
                    
                    
                }
                
                
            }
            }
           }
    
    
    
    
    int remainD = 0;
    int totalPriceLowestM =0;
    
    ansPriceLowestTotal = ansPriceLowest1+ansPriceLowest2;
    if (d>=ansPriceLowestTotal){
        cout<<ansTicket1<<','<<ansTicket2<<','<<ansPriceLowestTotal;}
    else if (x1 == 0 & x2 ==0){
        cout<<0<<','<<0<<','<<0;

        
    }
    
    
    else {
        if (m==1){
            
            remainD=d-pricemax1;
            int countmax2_2=0;
            int pricemax2_2=0;
             for (int i=0 ; i<10000  ;i++){
                 
                 if (remainD>=totalPrice2[i]){
                     countmax2_2=countmax2_2+1;
                     pricemax2_2=totalPrice2[i];}
                 else{
                     break;}
             }
            totalPriceLowestM = pricemax1+pricemax2_2;
            cout<<countmax1<<','<<countmax2_2<<','<<totalPriceLowestM ;
            
                }
        else if (m==2){
            
            remainD=d-pricemax2;
           int countmax1_1=0;
           int pricemax1_1=0;
           for (int i=0 ; i<10000  ;i++){
               
               if (remainD>=totalPrice1[i]){
                   countmax1_1=countmax1_1+1;
                   pricemax1_1=totalPrice1[i];
                   }
               else{
                   break;}
           }
        totalPriceLowestM = pricemax1_1+pricemax2;
        cout<<countmax1_1<<','<<countmax2<<','<<totalPriceLowestM ;
            }
        else{
        cout<<countmax1For0<<','<<countmax2For0<<','<<ansSumPriceFor0 ;
            }
             
        
        
    }
        
        
        
        
        

    

    return 0 ;
}


