#pragma once
#include"Processor.h"
#include"FCFSProcessor.h"
#include"Process.h"
#include<iostream>
using namespace std;

//class Scheduler
//{
//public:
//	Queue<Process*> BLK;
//	Queue<Process*> TRM;
//
//	Scheduler() {
//		Process* PSESSptr;
//		for (int j = 0; j < 6; j++) {
//			for (int i = 0; i < 5; i++)
//			{
//				//int x = 4;
//				PSESSptr = new Process(i*j, i*j + 5, i*j + 35, i*j + 6, &i + 12, &i + 88);
//				FCFSptr[i].AddToRDY(PSESSptr);
//			}
//		}
//	}
//
//	void fillProcessor() {
//
//	}
//
//	//FCFSProcessor arr[] = { FCFSProcessor p1(5), FCFSProcessor p2(6), FCFSProcessor p3(88)}
//	FCFSProcessor* FCFSptr = new FCFSProcessor[5];
//	
//	
//	//while(trm != num of processes in neww){
//		Process* PSESSptr = nullptr;
//		//loop on the list of the processor to call update func
//		//pass the PSESSptr to update func as parameter
//		if (PSESSptr)
//		{
//			// check for the int from the update to put the processes into BLK , TRM, RUN
//			//if it was 0 ot 1 ot 2
//		}
//	
//		//make a cout << 
//	//}
//};

ostream& operator << (ostream& COUT, Scheduler& SS) {
	COUT << SS.printprocess();
	return COUT;
}

class Scheduler {
public:
	Queue<Process*> BLK;
	Queue<Process*> TRM;
	FCFSProcessor* FCFSptr = new FCFSProcessor[5];
	Scheduler() {
		Process* PSESSptr;
		
				for (int j = 0; j < 6; j++) {
					for (int i = 0; i < 5; i++)
					{
						//int x = 4;
						PSESSptr = new Process(i*j, i*j + 5, i*j + 35, i*j + 6, &i + 12, &i + 88);
						FCFSptr[i].AddToRDY(PSESSptr);
					}
				}

	}
	
	void Scheduler_Running() {
		while (TRM.Size() != 20)
		{
			Process* PSESSptr = nullptr;
			for (int i = 0; i < 6; i++) {
				FCFSptr[i].UpdateRandomNum(PSESSptr);
				if (PSESSptr == 0) {
					TRM.EnQueue(PSESSptr);
				}
				else if(FCFSptr[i].UpdateRandomNum(PSESSptr) == 1){
					
						BLK.EnQueue(PSESSptr);
					
				}
				else if (FCFSptr[i].UpdateRandomNum(PSESSptr) == 2) {
					PSESSptr = FCFSptr->getRun();
				}
			}
		}
	}
	
	
	void printprocess() {
	
	
		int mode;
		cout << "-------------*Process Scheduler*--------------" << endl;
		cout << "For Interactive Mode press ->>>> 1 " << endl;
		cout << "For Step-by-Step Mode press ->>>> 2 " << endl;
		cout << "For Silent Mode press ->>>> 3 " << endl;
		cin >> mode;
		if (mode == 1) {
			cout << "----------- RDY Processes ------------" << endl;

			cout << "----------- BLK Processes ------------" << endl;
			cout << "----------- RUN Processes ------------" << endl;
			cout << "----------- TRM Processes ------------" << endl;
			cout << "PRESS ANY KEY TO MOVE TO NEXT STEP !" << endl;
			cin.ignore();
		}
	
	}
};

