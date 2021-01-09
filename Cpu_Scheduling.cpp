// Cpu_Scheduling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> 
using namespace std;

int sjf_pocess_state(int cpu_burst[][1], int process_gelis[][1], int process_oncelik[][1], int cpuDeger, int process_oncelik_deger, int process_gelis_deger,int whoProcess) {
   
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
    return toplam_wait;
}
//matrisimizi küçükten büyüðe sýralayalým.
void fileDiziSayiSirala(int process_gelis[][1], int process_oncelik[][1], int  cpu_burst[][1]) {
     
    int i, j;
    if (process_gelis[0][0] == 0) {
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
    else {
        for (i = 0; i < 5; i++)
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
   
}
void fcfs(int process_gelis[][1], int cpu_burst[][1]) {
    std::cout << "Scheduling Method: First Come First Served.\n";
    std::cout << "Process Waiting Times:\n";
    int i, toplam_cpu_burst = 0, waiting_time = 0, wait = 0;
    float toplam_wait = 0.0;
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
    int i, toplam_cpu_burst = 0, waiting_time = 0, wait = 0, j, m;
    float toplam_wait = 0.0;

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
                std::cout << "P" << (i + 1) << ": " << waiting_time << " ms" << endl;
            }
            else {
                wait = sjf_pocess_state(cpu_burst, process_gelis, process_oncelik, 5, 3, 0, i);
                toplam_wait += wait;
                std::cout << "P" << (i + 1) << ": " << toplam_wait << " ms" << endl;
            }
            
        }
        else if (i == 1) { //P2
          
            wait=sjf_pocess_state(cpu_burst, process_gelis, process_oncelik, 4, 2, 1, i);
            toplam_wait += wait;
        }
        else if (i == 2) { //P3
            wait=sjf_pocess_state(cpu_burst, process_gelis, process_oncelik, 3, 1, 1, i); 
            toplam_wait += wait;
        }
        else if (i == 3) { //P4
            wait= sjf_pocess_state(cpu_burst, process_gelis, process_oncelik, 4, 2, 2, i);
            toplam_wait += wait;
        }
        else {//P5
            wait= sjf_pocess_state(cpu_burst, process_gelis, process_oncelik, 3, 1, 3, i);
            toplam_wait += wait;
        }

    }

    std::cout << "Average Waiting Time: " << (toplam_wait / 5) << " ms" << endl;
}
// Process önceliklerini büyükten küçüðe sýralama iþlemi
void fileDiziSayiSiralaPriority(int process_gelis[][1], int process_oncelik[][1], int  cpu_burst[][1]) {
    int  j,i;
    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (process_oncelik[i][0] < process_oncelik[j][0]) {
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
int priortiy_pocess_state(int cpu_burst[][1], int process_gelis[][1], int process_oncelik[][1], int cpuDeger, int process_oncelik_deger, int process_gelis_deger, int whoProcess) {
    
    int toplam_cpu_burst = 0, waiting_time = 0, toplam_wait = 0, wait = 0, m;

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
    return toplam_wait;
}
void priority(int cpu_burst[5][1], int process_gelis[5][1], int process_oncelik[5][1], int  fileDiziSayi[5][3]) {

    std::cout << "Scheduling Method: Priority Scheduling – Non-Preemptive\n";
    std::cout << "Process Waiting Times:\n";
    int i, toplam_cpu_burst = 0, waiting_time = 0,  wait = 0,j,m;
    float toplam_wait = 0.0;
    // Process önceliklerini büyükten küçüðe sýralama iþlemi
    //fileDiziSayiSiralaPriority(cpu_burst, process_gelis, process_oncelik);
  
    fileDiziSayiSirala(process_gelis, process_oncelik, cpu_burst);
    //prototip
    //priority_pocess_state(int cpu_burst[][1], int process_gelis[][1], int process_oncelik[][1], int cpuDeger, int process_oncelik_deger, int process_gelis_deger, int whoProcess)
    

    for (i = 0; i < 5; i++)
    {
        int b = 0;
        if (i == 0) { //P1
        
         waiting_time = process_gelis[i][0];
         if (waiting_time == 0) {
             wait = waiting_time;
             toplam_wait += wait;
             std::cout << "P" << (i + 1) << ": " << waiting_time << " ms" << endl;
         }
         else {
            // wait = priortiy_pocess_state(cpu_burst, process_gelis, process_oncelik, cpu_burst[i][0], process_oncelik[i][0], process_gelis[i][0], i);
             wait=priortiy_pocess_state(cpu_burst, process_gelis, process_oncelik, 5, 3, 0, i); //Doðru çalýþan bu yapý, üstteki ile kontrol eyle
             toplam_wait += wait;
             std::cout << "P" << (i + 1) << ": " << toplam_wait << " ms" << endl;
         }
        
        }
        else if (i == 1) { //P2

          //  wait = priortiy_pocess_state(cpu_burst, process_gelis, process_oncelik, cpu_burst[i][0], process_oncelik[i][0], process_gelis[i][0], i);
            wait = priortiy_pocess_state(cpu_burst, process_gelis, process_oncelik, 4, 2, 1, i);
            toplam_wait += wait;
        }
        else if (i == 2) { //P3
           // wait = priortiy_pocess_state(cpu_burst, process_gelis, process_oncelik, cpu_burst[i][0], process_oncelik[i][0], process_gelis[i][0], i);
            wait = priortiy_pocess_state(cpu_burst, process_gelis, process_oncelik, 3, 1, 1, i);
            toplam_wait += wait;

        }
        else if (i == 3) { //P4
            //wait = priortiy_pocess_state(cpu_burst, process_gelis, process_oncelik, cpu_burst[i][0], process_oncelik[i][0], process_gelis[i][0], i);
            wait=  priortiy_pocess_state(cpu_burst, process_gelis, process_oncelik, 4, 2, 2, i);
            toplam_wait += wait;

        }
        else {//P5
            //wait = priortiy_pocess_state(cpu_burst, process_gelis, process_oncelik, cpu_burst[i][0], process_oncelik[i][0], process_gelis[i][0], i);
            wait=  priortiy_pocess_state(cpu_burst, process_gelis, process_oncelik, 3, 1, 3, i);
            toplam_wait += wait;

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


    int model_sec = 0,option;

    cout << "CPU Scheduler Simulator"<<endl;
    std::cout << "1) Scheduling Method\n" << "2)  Preemptive Mode\n" << "3) Non-preemptive Mode\n"
        << "4) Show Result\n" << "5) End Program \n"<<endl;
    cout << "Option >" << endl;
    cin >> option;
    cout << endl;
    switch (option)
    {

     case 1:      
         std::cout << "1) First Come First Served\n" << "2)  Shortest Job First – Non-Preemptive\n" << "3) Shortest Job First –Preemptive\n"
             << "4) Priority Scheduling – Non-Preemptive\n" << "5) Priority Scheduling –Preemptive \n" << "6)  Round Robin Scheduling – time_quantum=2\n\n";
         std::cin >> model_sec;
        break;
     case 2:

         cout << "Preemptive Mode: This is a clock-driven mode, in which the clock is a counter that is incremented each simulated second.The clock is "<<
             "initially 0, and continues 'ticking' until all the jobs in the input have "<<
            " been serviced and left the system.This simulation runs until a " <<
             "particular number of jobs have been serviced.First jobs should obtain "<<
            " from input file.And each step simulator ask user if its need to put new "<<
            " job to ready queue or Continue to execution.New job should be added "<<
            " in pair format.Pair should consist Burst time and Priority(10:1).This "<<
            " job should be taking into account by your program. "<<endl;
         break;

     case 3:

         cout << "Non-preemptive Mode: This mode is similar to Step-by-Step mode but " <<
             "its difference is simulator don’t ask to user at each time tick for new " <<
             " job.Simulator should use input file for decision process" << endl;
         break;

     case 4:
         fcfs(process_gelis, cpu_burst);
         cout <<  endl;
         sjf(cpu_burst, process_gelis, process_oncelik, fileDiziSayi);
         cout << endl;
         priority(cpu_burst, process_gelis, process_oncelik, fileDiziSayi);
         cout << endl;
         break;

     case 5:
         cout << " End Program: If user chooses this option, program show report to user " <<
             " (As described Step 4) and write output file that given with ' - o' option " <<
             " and terminated." << endl;
         break;
    default:
        cout << "Seçim Yapýnýz " << endl;
        break;
    }

    // Ayrý ayrý göstermek istendiðinde kullanýnýz.
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
        priority(cpu_burst, process_gelis, process_oncelik, fileDiziSayi);
        
    }
    else if (model_sec == 5) {
        std::cout << "Scheduling Method: Priority Scheduling –Preemptive, kodlanmadý" << endl;
    }
    else if (model_sec == 6) {

        std::cout << "Scheduling Method: Round Robin Scheduling,kodlanmadý \n";
       
    }
    return 0;
}
 
