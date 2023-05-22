#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Scheduler.h"
#include"Queue.h"
#include"math.h"



class UI
{
public:
	void PrintMode() {
		Scheduler SS1;
		SS1.printprocess();
		SS1.Scheduler_Running();
		
	}

	void write_processess(Queue<Processor*>* listofprocessors,Queue<Process*>* TRM, int forking_counter, int killed_counter) {
		ofstream myfile;
		myfile.open("output.txt");

		myfile << "TT" << " " << "pid" << " " << "AT" << " " << "CT" << " " << "iod" << " " << "WT" << " " << "RT" << " " << "TRT\n";
		int c = TRM->Size();
		// calculating averges 
		double allWT = 0;
		double allRT = 0;
		double allTRT = 0;
		for (int i = 0; i < c; i++) {
			Process* Process = TRM->DeQueue();
			allWT = allWT + Process->getwaitingtime();
			allTRT = allTRT + Process->getterminationtime();
			myfile << Process->getturnroundtime() << " " << Process->getPid() << " " << Process->getCT() << " " << Process->getNumIoOps() << " " << Process->getwaitingtime() << " " << Process->getturnroundtime() <<
				" " << Process->getterminationtime() << " \n";
		}
		myfile << "---------------------------------------------------------------------\n";
		myfile << "Number of processes:  " << c << "\n";
		myfile << "---------------------------------------------------------------------\n";
		myfile << "AVG WT = " << allWT / c << "  " << "AVG RT = " << allRT / c << "  " << "AVG TRT = " << allTRT / c << "  \n";
		myfile << "Forking %:  " << 100 * abs((forking_counter) / c) << "\n";
		myfile << "Killing %:  " << 100 * abs((killed_counter) / c) << "\n";
		myfile << "processors: " << listofprocessors->Size() << "\n";
		myfile << "Processors load" << "\n";
		int numofprocessors = listofprocessors->Size();
		for (int i = 0; i < numofprocessors; i++) {
			Processor* p = listofprocessors->DeQueue();
			myfile << "P" << p->getprocessorid() << " : " << 100 * (p->getbusytime() / allTRT) << "   ";
		}
		myfile << "\n";
		myfile << "Processors Utiliz" << "\n";
		int toal_Utiliz = 0;
		for (int i = 0; i < numofprocessors; i++) {
			Processor* p = listofprocessors->DeQueue();
			myfile << "P" << p->getprocessorid() << " : " << 100 * (p->getbusytime() / (p->getbusytime() + p->getidealtime())) << "   ";
			toal_Utiliz = toal_Utiliz + 100 * (p->getbusytime() / (p->getbusytime() + p->getidealtime()));
		}
		myfile << "average UTILIZ = " << (toal_Utiliz / c) * 100 << "\n";
		myfile.close();
	}








	
};

