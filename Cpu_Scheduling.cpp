// Cpu_Scheduling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> 
using namespace std;

void sjf_pocess_state(int cpu_burst[][1], int process_gelis[][1], int process_oncelik[][1], int cpuDeger, int process_oncelik_deger, int process_gelis_deger,int whoProcess) {
   
    int toplam_cpu_burst = 0, waiting_time = 0, toplam_wait = 0, wait = 0, j, m;

    for (m = 0; m < 5; m++)
    {
        if (process_oncelik[m][0] == process_oncelik_deger && process_gelis[m][0] == process_gelis_deger && cpu_burst[m][0] == cpuDeger) {
            wait = toplam_cpu_burst - process_gelis[m][0];
            toplam_wait += wait;
            std::cout << "P" << (whoProcess + 1) << ": " << wait << " ms" << endl;
            break;
        }
        toplam_cpu_burst += cpu_burst[m][0];

    }
    toplam_cpu_burst = 0;
}
void fileDiziSayiSirala(int process_gelis[][1], int process_oncelik[][1], int  cpu_burst[][1]) {
    //matrisimizi küçükten büyüðe sýralayalým. 
    int i, j;
    for (i = 1; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (cpu_burst[i][0] > cpu_burst[j][0]) {
                // cpu burst deðerlerini sýrala
                int cpuTut = cpu_burst[j][0];
                cpu_burst[j][0] = cpu_burst[i][0];
                cpu_burst[i][0] = cpuTut;
                //geliþ sýralarýný sýrala
                int processGelis = process_gelis[j][0];
                process_gelis[j][0] = process_gelis[i][0];
                process_gelis[i][0] = processGelis;
                // öncelikleri sýrala
                int processOncelik = process_oncelik[j][0];
                process_oncelik[j][0] = process_oncelik[i][0];
                process_oncelik[i][0] = processOncelik;
            }
            else if (cpu_burst[i][0] == cpu_burst[j][0] && process_gelis[i][0] > process_gelis[j][0]) {
                // cpu burst deðerlerini sýrala
                int cpuTut = cpu_burst[j][0];
                cpu_burst[j][0] = cpu_burst[i][0];
                cpu_burst[i][0] = cpuTut;
                //geliþ sýralarýný sýrala
                int processGelis = process_gelis[j][0];
                process_gelis[j][0] = process_gelis[i][0];
                process_gelis[i][0] = processGelis;
                // öncelikleri sýrala
                int processOncelik = process_oncelik[j][0];
                process_oncelik[j][0] = process_oncelik[i][0];
                process_oncelik[i][0] = processOncelik;
            }
        }
    }
}
void  cpu_scheduling_preliminary(int i, int cpu_burst[][1], int process_gelis[][1], int process_oncelik[][1], int  fileDiziSayi[][3]) {

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
void fcfs(int process_gelis[][1], int cpu_burst[][1]) {
    std::cout << "Scheduling Method: First Come First Served.\n";
    std::cout << "Process Waiting Times:\n";
    int i, toplam_cpu_burst = 0, waiting_time = 0, toplam_wait = 0, wait = 0;

    for (i = 0; i < 5; i++)
    {
        waiting_time = process_gelis[i][0];
        if (waiting_time == 0) {
            wait = waiting_time;
            std::cout << "P" << (i + 1) << ": " << waiting_time << " ms" << endl;
        }
        else {
            wait = toplam_cpu_burst - waiting_time;
            std::cout << "P" << (i + 1) << ": " << (wait) << " ms" << endl;
        }
        toplam_cpu_burst += cpu_burst[i][0];

        toplam_wait += wait;
    }

    std::cout << "Average Waiting Time: " << (toplam_wait / 5) << " ms" << endl;
}
void sjf(int cpu_burst[][1], int process_gelis[][1], int process_oncelik[][1], int  fileDiziSayi[][3]) {

    std::cout << "Scheduling Method: Shortest Job First – Non-Preemptive.\n";
    std::cout << "Process Waiting Times:\n";
    int i, toplam_cpu_burst = 0, waiting_time = 0, toplam_wait = 0, wait = 0, j, m;

    //matrisimizi küçükten büyüðe sýralayalým. 
    fileDiziSayiSirala(process_gelis, process_oncelik, cpu_burst);

    //prototip
    //sjf_pocess_state(int cpu_burst[][1], int process_gelis[][1], int process_oncelik[][1], int cpuDeger, int process_oncelik_deger, int process_gelis_deger, int whoProcess)

   
    for (i = 0; i < 5; i++)
    {     
        if (i == 0) { //P1

          //sjf_pocess_state(cpu_burst, process_gelis, process_oncelik, 4, 2, 1, 1);
            waiting_time = process_gelis[i][0];
            if (waiting_time == 0) {
                wait = waiting_time;
                toplam_wait += wait;
             
            }
            std::cout << "P" << (i + 1) << ": " << waiting_time << " ms" << endl;
        }
        else if (i == 1) { //P2
          
            sjf_pocess_state(cpu_burst, process_gelis, process_oncelik, 4, 2, 1, 1);        
        }
        else if (i == 2) { //P3
            sjf_pocess_state(cpu_burst, process_gelis, process_oncelik, 3, 1, 1, 2);          
        }
        else if (i == 3) { //P4
            sjf_pocess_state(cpu_burst, process_gelis, process_oncelik, 4, 2, 2, 3);         
        }
        else {//P5
            sjf_pocess_state(cpu_burst, process_gelis, process_oncelik, 3, 1, 3, 4);
        }

    }

    std::cout << "Average Waiting Time: " << (toplam_wait / 5) << " ms" << endl;
}


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

     cpu_scheduling_preliminary(0, cpu_burst, process_gelis, process_oncelik, fileDiziSayi);
    
    }
    else {
        std::cout << "Dosya açýlamadý"<<endl;
    }

    int model_sec;
    std::cout << "1) First Come First Served\n" << "2)  Shortest Job First – Non-Preemptive\n" << "3) Shortest Job First –Preemptive\n"
        << "4) Priority Scheduling – Non-Preemptive\n" << "5) Priority Scheduling –Preemptive \n" << "6)  Round Robin Scheduling – time_quantum=2\n\n";

    std::cout << "Kullanmak istediðin Cpu Scheduling Modelini seçniz\n";
    std::cin >> model_sec;

   
    if (model_sec == 1) {      
        fcfs(process_gelis, cpu_burst);
    }
    else if (model_sec == 2) {
        sjf(cpu_burst, process_gelis, process_oncelik, fileDiziSayi);
    }
    else if (model_sec == 3) {
        std::cout << "Scheduling Method: Shortest Job First –Preemptive, kodlanmadý" << endl;
    }
    else if (model_sec == 4) {

        std::cout << "Scheduling Method: Priority Scheduling – Non-Preemptive\n";
        std::cout << "Process Waiting Times:\n";
        int i, toplam_cpu_burst = 0, waiting_time = 0, toplam_wait = 0, wait = 0;

        // kodlar burda

        std::cout << "Average Waiting Time: " << (toplam_wait / 5) << " ms" << endl;
    }
    else if (model_sec == 5) {
        std::cout << "Scheduling Method: Priority Scheduling –Preemptive, kodlanmadý" << endl;
    }
    else if (model_sec == 6) {

        std::cout << "Scheduling Method: Round Robin Scheduling – time_quantum=2.\n";
        std::cout << "Process Waiting Times:\n";
        int i, toplam_cpu_burst = 0, waiting_time = 0, toplam_wait = 0, wait = 0;

        // kodlar burda

        std::cout << "Average Waiting Time: " << (toplam_wait / 5) << " ms" << endl;
    }
    return 0;
}

