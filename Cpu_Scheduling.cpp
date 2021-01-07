// Cpu_Scheduling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> 
using namespace std;

//void cpu_scheduling_preliminary(int i, int cpu_burst[5][1], int process_gelis[5][1], int process_oncelik[5][1], int  fileDiziSayi[5][3]);

int main()
{
    setlocale(LC_ALL, "Turkish");

    ifstream file;
    file.open("file_input.txt");

  
    int  fileDiziSayi[5][3] = { {0,0,0}, {0,0,0} ,{0,0,0} ,{0,0,0} ,{0,0,0} };
    int cpu_burst[5][1] = { {0}, {0} ,{0} ,{0} ,{0} };
    int process_gelis[5][1] = { {0}, {0} ,{0} ,{0} ,{0} };
    int process_oncelik[5][1] = { {0}, {0} ,{0} ,{0} ,{0} };
   
    char karater;

    int satir_idx = 0, stn_idx = 0, ikinokta_syc = 0;

    if (file) {
      
        while (file.get(karater)) {
            if (karater != '\n') {
                if (karater != ':') {

                   string s1{ karater };                 
                   fileDiziSayi[satir_idx][stn_idx] = stoi(s1);          
                    stn_idx++;
                }
                else {
                    ikinokta_syc++;
                }
                if (ikinokta_syc == 2) {
                    ikinokta_syc = 0;
                }
                if (stn_idx > 2) {
                    stn_idx = 0;
                }
                if (ikinokta_syc == 0 && stn_idx == 0) {
                    satir_idx++;
                }
            }
      }

     //cpu_scheduling_preliminary(0, cpu_burst, process_gelis, process_oncelik, fileDiziSayi);

        int i = 0,j;
        while (i < 3) {

            for (j = 0; j < 5; j++)
            {
                if (i == 0) {
                    cpu_burst[j][0] = fileDiziSayi[j][i];
                }
                else if (i == 1) {
                    process_gelis[j][0] = fileDiziSayi[j][i];
                }
                else {
                    process_oncelik[j][0] = fileDiziSayi[j][i];
                }
            }
            i++;
        }
      
    }
    else {
        cout << "Dosya açýlamadý"<<endl;
    }

    int model_sec;
    cout << "1) First Come First Served\n" << "2)  Shortest Job First – Non-Preemptive\n" << "3) Shortest Job First –Preemptive\n"
        << "4) Priority Scheduling – Non-Preemptive\n" << "5) Priority Scheduling –Preemptive \n" << "6)  Round Robin Scheduling – time_quantum=2\n\n";

    cout << "Kullanmak istediðin Cpu Scheduling Modelini seçniz\n";
    cin >> model_sec;

   
    if (model_sec == 1) {
        cout << "Scheduling Method: First Come First Served.\n";
        cout << "Process Waiting Times:\n";
        int i,toplam_cpu_burst=0,waiting_time=0,toplam_wait=0,wait=0;

        for (i = 0; i < 5; i++)
        {
            waiting_time = process_gelis[i][0];
            if (waiting_time == 0) {
                wait = waiting_time;
                cout << "P" << (i + 1) << ": "<<waiting_time << " ms" << endl;
            }
            else {
                wait = toplam_cpu_burst - waiting_time;
                cout << "P" << (i + 1) << ": "<<(wait) << " ms" << endl;
            }
            toplam_cpu_burst += cpu_burst[i][0];

            toplam_wait += wait;
        }

        cout << "Average Waiting Time: "<< (toplam_wait/5) <<" ms" <<endl;
    }

    else if (model_sec == 2) {

        cout << "Scheduling Method: Shortest Job First – Non-Preemptive.\n";
        cout << "Process Waiting Times:\n";
        int i, toplam_cpu_burst = 0, waiting_time = 0, toplam_wait = 0, wait = 0,j,m;

        for (i = 0; i < 5; i++)
        {
            waiting_time = process_gelis[i][0];
            if (waiting_time == 0) {
                wait = waiting_time;
                cout << "P" << (i + 1) << ": " << waiting_time << " ms" << endl;
            }
            else {
                
                    int currentProcessArrivalTime = process_gelis[i][0];
                    for (m = i+1; m < 5; m++)
                    {
                        if (cpu_burst[i][0] > cpu_burst[m][0]) {
                            //cpu_burst için deðiþim
                            int cpuTut = cpu_burst[i][0];
                            cpu_burst[i][0] = cpu_burst[m][0];
                            cpu_burst[m][0] = cpuTut;
                            //process_gelis için deðiþim
                            int processGelisTut = process_gelis[i][0];
                            process_gelis[i][0] = process_gelis[m][0];
                            process_gelis[m][0] = processGelisTut;


                            toplam_cpu_burst += cpu_burst[i][0];
                            wait = toplam_cpu_burst - currentProcessArrivalTime;
                            toplam_wait += wait;
                        }
                       
                    }
                    cout << "P" << (i + 1) << ": " << (toplam_cpu_burst - currentProcessArrivalTime) << " ms" << endl;


                    // Sýralama sonrasý ilgili sýralamayý eski haline getir, diðer processler etkilenmesin, aþaðýdaki döngüye fonksiyon yazýlacak
                    int i = 0;
                    while (i < 3) {

                        for (j = 0; j < 5; j++)
                        {
                            if (i == 0) {
                                cpu_burst[j][0] = fileDiziSayi[j][i];
                            }
                            else if (i == 1) {
                                process_gelis[j][0] = fileDiziSayi[j][i];
                            }
                            else {
                                process_oncelik[j][0] = fileDiziSayi[j][i];
                            }
                        }
                        i++;
                    }
            }
            toplam_cpu_burst += cpu_burst[i][0];
        }

        cout << "Average Waiting Time: "<< (toplam_wait/5)<<" ms"<< endl;

    }



    return 0;
}
/*
void  cpu_scheduling_preliminary(int i, int cpu_burst[5][1], int process_gelis[5][1], int process_oncelik[5][1], int  fileDiziSayi[5][3]) {
 
    int j;
        while (i < 3) {

            for (j = 0; j < 5; j++)
            {
                if (i == 0) {
                    cpu_burst[j][0] = fileDiziSayi[j][i];
                }
                else if (i == 1) {
                    process_gelis[j][0] = fileDiziSayi[j][i];
                }
                else {
                    process_oncelik[j][0] = fileDiziSayi[j][i];
                }
            }
            i++;
        }
        int b = 0;
}
*/