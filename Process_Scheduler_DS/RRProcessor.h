#pragma once
#include"Processor.h"
#include"CircularQueue.h"
class RRProcessor:public Processor
{
private:

	CircularQueue<Process*, 100> RDY;
	int time_slice;
public:
	
	RRProcessor(int numProcesses);
	virtual void AddToRDY(Process* p);
	virtual void RemoveProcess();
	virtual void ScheduleAlgo(Process* p);
	virtual int getidealtime();
	virtual int getbusytime();
	virtual void setidealtime(int ideal);
	virtual void setbusytime(int busy);

};

