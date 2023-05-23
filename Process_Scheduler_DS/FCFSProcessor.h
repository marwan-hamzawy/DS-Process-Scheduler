#pragma once
#include"Processor.h"
#include"Queue.h"

class FCFSProcessor:public Processor
{
private:
	Queue<Process*> RDY;
public:
	
	FCFSProcessor();
	FCFSProcessor(int numProcesses);
	 void AddToRDY(Process* p) override;
	 void RemoveProcess(Process* p) override;
	 void RemoveProcess2(Process* p);
	 void ScheduleAlgo(Process* p) override;
	//virtual void printStats() override;
	 int getidealtime() override;
	 int getbusytime() override;
	 void setidealtime(int ideal) override;
	 void setbusytime(int busy) override;
	 int UpdateRandomNum(Process*& p) override;
	 void PrintProcessor() override;
	 bool forkrequired(Process*& p,int fk,int at,int num);
	 int ShortSizeFCFS();

};

