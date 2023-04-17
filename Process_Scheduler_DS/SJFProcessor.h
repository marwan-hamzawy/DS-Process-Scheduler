#pragma once
#include"Processor.h"
#include"PriorityQueue.h"
class SJFProcessor:public Processor
{
private:
	PriorityQueue<Process*> RDY;
public:

	SJFProcessor(int numProcesses);
	virtual void AddToRDY(Process* p);
	virtual void RemoveProcess();
	virtual void ScheduleAlgo(Process* p);
	virtual int getidealtime();
	virtual int getbusytime();
	virtual void setidealtime(int ideal);
	virtual void setbusytime(int busy);
};

