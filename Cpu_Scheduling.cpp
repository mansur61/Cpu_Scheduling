// Cpu_Scheduling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> 
using namespace std;

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

    int satir_idx = 0, stn_idx = 0, ikinokta_syc = 0,b;

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
        int i=0,j;
        while (i < 3) {

            for ( j = 0; j < 5; j++)
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
        cout << "Dosya a��lamad�"<<endl;
    }

    int model_sec;
    cout << "Kullanmak istedi�in Cpu Scheduling Modelini se�niz\n";
    cin >> model_sec;

    cout << "1) First Come First Served\n" << "2)  Shortest Job First � Non-Preemptive\n" << "3) Shortest Job First �Preemptive\n"
        << "4) Priority Scheduling � Non-Preemptive\n" << "5) Priority Scheduling �Preemptive \n" << "6)  Round Robin Scheduling � time_quantum=2\n";

    if (model_sec == 1) {
        cout << "Scheduling Method: First Come First Served.\n";
        cout << "Process Waiting Times:\n";

        // Kodlar� buraya yaz�n�z

        cout << "Average Waiting Time: \n";
    }



    return 0;
}
