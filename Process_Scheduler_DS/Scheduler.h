

//#pragma once
//#include"Processor.h"
//#include"FCFSProcessor.h"
//#include"Process.h"
//#include<iostream>
//using namespace std;
//
////class Scheduler
////{
////public:
////	Queue<Process*> BLK;
////	Queue<Process*> TRM;
////
////	Scheduler() {
////		Process* PSESSptr;
////		for (int j = 0; j < 6; j++) {
////			for (int i = 0; i < 5; i++)
////			{
////				//int x = 4;
////				PSESSptr = new Process(i*j, i*j + 5, i*j + 35, i*j + 6, &i + 12, &i + 88);
////				FCFSptr[i].AddToRDY(PSESSptr);
////			}
////		}
////	}
////
////	void fillProcessor() {
////
////	}
////
////	//FCFSProcessor arr[] = { FCFSProcessor p1(5), FCFSProcessor p2(6), FCFSProcessor p3(88)}
////	FCFSProcessor* FCFSptr = new FCFSProcessor[5];
////
////
////	//while(trm != num of processes in neww){
////		Process* PSESSptr = nullptr;
////		//loop on the list of the processor to call update func
////		//pass the PSESSptr to update func as parameter
////		if (PSESSptr)
////		{
////			// check for the int from the update to put the processes into BLK , TRM, RUN
////			//if it was 0 ot 1 ot 2
////		}
////
////		//make a cout <<
////	//}
////};
//
//
//
//
//class Scheduler {
//public:
//	Queue<Process*> BLK;
//	Queue<Process*> TRM;
//	FCFSProcessor* FCFSptr = new FCFSProcessor[5];
//	int mode;
//	int clock = 0;
//	Scheduler() {
//		Process* PSESSptr;
//		int y = 1;
//				for (int j = 0; j < 6; j++) {
//					for (int i = 0; i < 5; i++)
//					{
//						//int x = 4;
//
//						PSESSptr = new Process(y, i*j + 5, i*j + 35, i*j + 6, &i + 12, &i + 88);
//						FCFSptr[i].AddToRDY(PSESSptr);
//						y++;
//					}
//				}
//
//	}
//
//	void UpdateIO()
//	{
//		Process* Run = nullptr;
//		if (BLK.IsEmpty())
//		{
//			return;
//		}
//		BLK.FRONT(Run);
//		int randomNumber = rand() % 100;
//		if (Run && randomNumber < 50)
//		{
//			BLK.DeQueue();
//			FCFSptr[0].AddToRDY(Run);
//		}
//	}
//
//
//	void Scheduler_Running() {
//		while (TRM.Size() != 30)
//		{
//			Process* PSESSptr = nullptr;
//			if (clock == 48)
//			{
//				cout << "";
//			}
//			for (int i = 0; i < 5; i++) {
//				int x = FCFSptr[i].UpdateRandomNum(PSESSptr);
//
//				if (PSESSptr) {
//
//					if (x == 1) {
//						BLK.EnQueue(PSESSptr);
//					}
//					else if (x == 2)
//					{
//						TRM.EnQueue(PSESSptr);
//					}
//				}
//				PSESSptr = nullptr;
//			}
//			UpdateIO();
//			printprocess();
//		}
//	}
//
//
//	void printprocess() {
//		if (clock==0)
//		{
//			cout << "Current timer is : " << clock;
//
//			cout << "-------------*Process Scheduler*--------------" << endl;
//			cout << "For Interactive Mode press ->>>> 1 " << endl;
//			cout << "For Step-by-Step Mode press ->>>> 2 " << endl;
//			cout << "For Silent Mode press ->>>> 3 " << endl;
//			cin >> mode;
//		}
//		clock++;
//
//		cout << "Current timer is : " << clock;
//
//		if (mode == 1) {
//			cout << "\n----------- RDY Processes ------------\n" << endl;
//
//			for (int i = 0; i < 5; i++) {
//				FCFSptr[i].PrintProcessor();
//				cout << "\n";
//			}
//
//			cout << "\n----------- BLK Processes ------------\n" << endl;
//
//			BLK.Display();
//
//			cout << "\n----------- RUN Processes ------------\n" << endl;
//
//			for (int i = 0; i < 5; i++) {
//				Process* temp = FCFSptr[i].getRun();
//				if (temp) {
//					cout << "Processor: " << i << " > " << temp << "    ";
//				}
//			}
//			cout << "\n----------- TRM Processes ------------\n" << endl;
//
//			TRM.Display();
//
//			cout << "\nPRESS ANY KEY TO MOVE TO NEXT STEP !\n\n\n" << endl;
//			cin.get();
//		}
//
//	}
//};
//

#pragma once
#include "Processor.h"
#include "FCFSProcessor.h"
#include "Process.h"
#include <iostream>
#include <fstream>
using namespace std;

class Scheduler {
public:
    Queue<Process*> BLK;
    Queue<Process*> TRM;
    FCFSProcessor* FCFSptr;
    int mode;
    int clock;

    Scheduler() {
        FCFSptr = new FCFSProcessor[5];
        clock = 0;
        mode = 1;
        readProcessesFromFile("/Users/mohamedghaith/Documents/DS-Process-Scheduler/Process_Scheduler_DS/input.txt");
    }

    void readProcessesFromFile(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            cout << "Failed to open input file." << endl;
            return;
        }

        int numProcesses;
        inputFile >> numProcesses;

        for (int i = 0; i < numProcesses; i++) {
            int arrivalTime, pid, cpuTime, numIO;
            inputFile >> arrivalTime >> pid >> cpuTime >> numIO;
            cout << "Arrival time: " << arrivalTime << ", PID: " << pid << ", NumIO: " << numIO << endl;

            int* ioTimes = new int[numIO];
            int* ioDurations = new int[numIO];
            for (int j = 0; j < numIO; j++) {
                cout << "IO time " << j << ": " << ioTimes[j] << ", IO duration " << j << ": " << ioDurations[j] << endl;
            }

            Process* process = new Process(pid, arrivalTime, cpuTime, numIO, ioTimes, ioDurations);

            // Add the process FCFSProcessorz
            int index = i % 5; // Cycle through the processors
            FCFSptr[index].AddToRDY(process);
        }

        inputFile.close();
    }

    void UpdateIO() {
        Process* Run = nullptr;
        if (BLK.IsEmpty()) {
            return;
        }
        BLK.FRONT(Run);
        int randomNumber = rand() % 100;
        if (Run && randomNumber < 50) {
            BLK.DeQueue();
            FCFSptr[0].AddToRDY(Run);
        }
    }

    void Scheduler_Running() {
        while (TRM.Size() != 30) {
            Process* PSESSptr = nullptr;
            for (int i = 0; i < 5; i++) {
                int x = FCFSptr[i].UpdateRandomNum(PSESSptr);

                if (PSESSptr) {
                    if (x == 1) {
                        BLK.EnQueue(PSESSptr);
                    }
                    else if (x == 2) {
                        TRM.EnQueue(PSESSptr);
                    }
                }
                PSESSptr = nullptr;
            }
            printprocess(); // move printprocess() here
            UpdateIO();
        }
    }

    void printprocess() {
        if (clock == 0) {
            cout << "Current timer is: " << clock << endl;
            cout << "-------------*Process Scheduler*--------------" << endl;
            cout << "For Interactive Mode, press 1" << endl;
            cout << "For Step-by-Step Mode, press 2" << endl;
            cout << "For Silent Mode, press 3" << endl;
            cin >> mode;
        }
        clock++;

        cout << "Current timer is: " << clock << endl;

        if (mode == 1) {
            cout << "\n----------- RDY Processes ------------\n" << endl;

            for (int i = 0; i < 5; i++) {
                cout << "Processor " << i << ": ";
                FCFSptr[i].PrintProcessor();
                cout << endl;
            }

            cout << "----------- BLK Processes ------------" << endl;
            BLK.Display();
            cout << "----------- RUN Processes ------------" << endl;

            for (int i = 0; i < 5; i++) {
                cout << "Processor " << i << ": ";
                Process* temp = FCFSptr[i].getRun();
                if (temp) {
                    cout << temp->getPid();
                }
                cout << endl;
            }

            cout << "----------- TRM Processes ------------\n" << endl;
            TRM.Display();

            cout << "\nPRESS ANY KEY TO MOVE TO NEXT STEP!\n" << endl;
            cin.ignore();
            cin.get();
        }
    }
};