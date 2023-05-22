#pragma once
#include"Processor.h"
#include"PriorityQueue.h"
class SJFProcessor:public Processor
{
private:
    PriorityQueue<Process*> RDY;
public:

	SJFProcessor(int numProcesses);
	 void AddToRDY(Process* p) override;
	 void RemoveProcess(Process* p) override;

	 virtual void ScheduleAlgo(Process* p) override;
	 int getidealtime() override;
	 int getbusytime() override;
	 void setidealtime(int ideal) override;
	 void setbusytime(int busy) override;
	int UpdateRandomNum(Process*& p) override;
	int ShortSizeFCFS() override;

    void PrintProcessor();

    SJFProcessor();
};

