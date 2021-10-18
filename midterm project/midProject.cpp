#include <iostream>
using namespace std;

int main()
{
    //對每一個機台所分配到的訂單分析，判斷在哪個訂單前要維修
    int part_one_answer[51][1001];
    int machine_data[51][5] = { 0 };
    int order_data[1001][2] = { 0 };

    int order_num[51] = { 0 };
    for (int i = 1; i < 51; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if (part_one_answer[i][j] != 0)
            {
                order_num[i]++;
            }
            else
            {
                break;
            }
        }
    }
    //--------------------------------------------算出每個機器各處理多少訂單

    int machine_initial_delay[51] = { 0 };
    
    for (int i = 1; i < 51; i++)
    {
        float machine_production = 0;
        int machine_rate = machine_data[i][3];
        int time = 0;
        for (int j = 0; j < order_num[i]; j++)
        {
            machine_production = 0;
            while (machine_production < order_data[part_one_answer[i][j]][0])
            {
                time++;
                if (machine_rate <= machine_data[i][4])
                {
                    machine_rate = machine_data[i][4];
                }
                else
                {
                    machine_rate -= machine_data[i][1];
                }
                machine_production += machine_data[i][0] * machine_rate / static_cast<float>(100);

            }
            if (time > order_data[part_one_answer[i][j]][1])
            {
                machine_initial_delay[i] += time - order_data[part_one_answer[i][j]][1];
            }
        }
    }
    //-----------------------算出每台機器在不維修情形下延遲時間各是多少

    int part_one_answer_repair[51][1000] = { 0 };

    for (int i = 1; i < 51; i++)
    {
        if (part_one_answer[i][0] == 0)
        {
            continue;
        }
        while (true)
        {
            int judge = 0;
            int min_delay_time = machine_initial_delay[i];

            for (int j = 0; j < order_num[i]; j++)
            {
                if (part_one_answer_repair[i][j] == 0)
                {
                    int delay_time_temp = 0;
                    float machine_production = 0;
                    int machine_rate = machine_data[i][3];
                    int time = 0;
                    
                    for (int k = 0; k < order_num[i]; k++)
                    {
                        machine_production = 0;
                        if (k == j or part_one_answer_repair[i][k] == 1)
                        {
                            time += machine_data[i][2];
                        }
                        while (machine_production < order_data[part_one_answer[i][k]][0])
                        {
                            time++;
                            if (machine_rate <= machine_data[i][4])
                            {
                                machine_rate = machine_data[i][4];
                            }
                            else
                            {
                                machine_rate -= machine_data[i][1];
                            }
                            machine_production += machine_data[i][0] * machine_rate / static_cast<float>(100);

                        }
                        if (time > order_data[part_one_answer[i][j]][1])
                        {
                            delay_time_temp += time - order_data[part_one_answer[i][j]][1];
                        }
                    }
                    if (delay_time_temp < min_delay_time)
                    {
                        min_delay_time = delay_time_temp;
                        judge = j;
                    }



                }
            }
            if (judge == 0)
            {
                break;
            }
            else
            {
                machine_initial_delay[i] = min_delay_time;
                part_one_answer_repair[i][judge] = 1;
            }
        }
    }
//---------------------------用part_one_answer_repair紀錄在哪些訂單前維修能最小化延遲時間

    //之後對時間分析，若該時間要開始的訂單正好是前一部分被判定生產前要維修的訂單，則進行維修，若滿了則不進行維修，也不補修
    int fixing_limit;
    int time_limit = 1000;
    int* repair_at_t = new int[time_limit];
    int machine_production = 0;
    for (int i = 1; i < 51; i++)
    {
        int time = 0;
        int machine_rate = machine_data[i][3];
        if (part_one_answer[i][0] == 0)
        {
            continue;
        }
        for (int j = 0; j < order_num[i]; j++)
        {
            machine_production = 0;
            if (part_one_answer_repair[i][j] == 1)
            {
                for (int k = time + 1; k <= time + machine_data[i][2]; k++)
                {
                    if (repair_at_t[k] == fixing_limit)
                    {
                        part_one_answer_repair[i][j] = 0;
                        break;
                    }
                }
                if (part_one_answer_repair[i][j] == 1)
                {
                    for (int k = time + 1; k <= time + machine_data[i][2]; k++)
                    {
                        if (time == time_limit - 1)
                        {
                            time_limit *= 2;
                            int* temp = new int[time_limit];
                            for (int p = 1; p < time_limit; p++)
                            {
                                temp[p] = repair_at_t[p];
                            }
                            delete[]repair_at_t;
                            repair_at_t = temp;
                        }
                        repair_at_t[k]++;
                    }
                    time += machine_data[i][2];
                }
              
               
                
            }
            while (machine_production < order_data[part_one_answer[i][j]][0])
            {
                time++;
                if (machine_rate <= machine_data[i][4])
                {
                    machine_rate = machine_data[i][4];
                }
                else
                {
                    machine_rate -= machine_data[i][1];
                }
                machine_production += machine_data[i][0] * machine_rate / static_cast<float>(100);

            }
        }
    }
    //-------------------------------------再算一次每一台機器如何生產訂單，但這次加入維修判斷，若是該次維修或維修時段已達
    //-------------------------------------同一段時間的維修上限則從part_one_answer_repair中刪去，也就是從1變0。

 
}




