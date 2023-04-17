#pragma once
#include"Processor.h"
#include"Queue.h"

class FCFSProcessor:public Processor
{
private:
	Queue<Process*> RDY;
public:
	
	
	FCFSProcessor(int numProcesses);
	virtual void AddToRDY(Process* p);
	virtual void RemoveProcess();
	virtual void ScheduleAlgo(Process* p);
	virtual int getidealtime() ;
	virtual int getbusytime() ;
	virtual void setidealtime(int ideal) ;
	virtual void setbusytime(int busy) ;
};

