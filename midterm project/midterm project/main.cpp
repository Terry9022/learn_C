//
//  part1.cpp
//  midterm project
//
//  Created by Terry Lu on 2020/12/12.
//  Copyright © 2020 Terry Lu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {

    //創立變數 讀入資料
    int machine_num =  0; //機台總數
    int order_num = 0; //訂單總數,
    int fixing_limit = 0; //同時間維修機台上限

    double machine_data[51][5] = {0};
    //每機台的各項狀況，同一橫列中左至右依序為該機台的理論生產速率、衰減率、維修所需時數、初始產率、產率下限
    //（儲存機台數據的二維陣列第0列空掉，由第1列開始代表機台1）

    double order_data[1000][3] = {0};
    //每一橫列兩個數字，第一個存該訂單需求量，第二個存該訂單截止時刻，第三個存訂單編號
    //（這個陣列的位置代表排名，不代表編號，因此第0列有資料）


    cin >> machine_num >> order_num >> fixing_limit;


    for (int i = 1; i <= machine_num; i++){
        cin >> machine_data[i][0] >> machine_data[i][1] >> machine_data[i][2] >> machine_data[i][3] >> machine_data[i][4];
    }

    for (int i = 0; i < order_num; i++){
        cin >> order_data[i][0] >> order_data[i][1];
        order_data[i][2] = static_cast<double>(i + 1);
    }


    // 重新安排訂單順序 使用sort的stable特性，也就是說先排序過的東西，再經過排序如果同等時其順序仍不變

    std::sort(order_data, order_data + order_num, [](double a, double b){
        return a[0] < b[0]; // 升序排列訂單數量
    });

    std::sort(order_data, order_data + order_num, [](double a, double b){
        return a[1] < b[1]; // 升序排列訂單期限
    });

    // 現在order_data已經經過排序了



    //算每張機台的能力值，以（a * (p + L) / 2）當作能力值，也就是總量與底線的平均值

    double machine_data_power[50][2] = {0};  //每張機台的能力值陣列，第0行存機台編號，第1行存機台能力
    for (int i = 0; i < machine_num; i++){
        //（a * (p + L) / 2）
        double power =  machine_data[i][0] * ((machine_data[i][3] + machine_data[i][4])/2);
        machine_data_power[i][0] = i + 1;
        machine_data_power[i][1] = power;
    }

    std::sort(machine_data_power, machine_data_power + machine_num, [](int* a, int* b){
        return a[1] > b[1];
    });

    //接著我們找出能力值的總和，單一能力值/總能力值即為要拿的訂單數比例，若小於1/總訂單數則定為1/總訂單數
    double totalPower = 0;
    for (int i = 0; i < machine_num; i++) {
        totalPower += machine_data_power[i][1];
    }
    for (int i = 0; i < machine_num; i++) {
        if (machine_data_power[i][1] / totalPower < 1.0 / order_num)
            machine_data_power[i][1] = 1.0 / order_num;
        else
            machine_data_power[i][1] /= totalPower;
    }
    //此時machine_data_power由強到弱存下了每機台對應的比例

    int part_one_answer[51][1000] = {0}; //此為結果陣列，一樣沒用到第0列
    //接著分出每機台要做的訂單張數，在終止點存下1001（因為訂單沒有第1001張）
    for (int i = 0; i < machine_num; i++) {
        int machine_load = static_cast<int>(round(order_num * machine_data_power[i][1]));
        for (int j = machine_load; j < order_num; j++) {
            part_one_answer[static_cast<int>(machine_data_power[i][0])][j] = 1001;
        }
    }
    
    //接著開始分配訂單，最外面迴圈選的是結果陣列的直排，內圈選機台
    //概念上來說我們輪流發每台機器的第一張訂單，接著發每台的第二張，依此類推，遇到1001就不發
    int order_i = 0; //用來表示目前發到第幾張訂單（這裡的第幾是指排名上的第幾）
    for (int i = 0; i < order_num; i++) {
        for (int j = 1; j <= machine_num; j++) {
            if (part_one_answer[j][i] != 1001){
                part_one_answer[j][i] = static_cast<int>(order_data[order_i][3]);
                order_i++;
            }
            if (order_i == order_num)
                break;
        }
        if (order_i == order_num)
            break;
    }
    
    
    //最後進行輸出
    for (int i = 1; i <= machine_num; i++) {
        for (int j = 0; j < order_num; j++) {
            if (part_one_answer[i][j] == 1001){
                if (i == machine_num)
                    break;
                else{
                    cout << endl;
                    break;
                }
            }
            else if (j == 0)
                cout << part_one_answer[i][j];
            else
                cout << "," << part_one_answer[i][j];
        }
    }

    return 0 ;


}
