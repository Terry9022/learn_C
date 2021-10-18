//
//  main.cpp
//  hw0
//
//  Created by Terry Lu on 2020/9/17.
//  Copyright © 2020 Terry Lu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int x1,x2,p1,p2,t,total;
    cin>>x1>>x2>>p1>>p2>>t;
    total=x1*p1+x2*p2;

        if( t>=total )
        {
            cout<<t-total;
        }
        else
        {
            cout<<-1<<","<<total-t;
        }
    return 0;
}


