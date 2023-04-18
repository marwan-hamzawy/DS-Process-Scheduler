#pragma once
#include"Process.h"
class Processor
{
private:
	
	int numProcesses; // number of processes in the ready queue
	double current_time;
	

public:
	int idealtime;
	int busytime;
	double current_time;
	Process* Run;
	Processor(int numProcesses);
	virtual void ScheduleAlgo(Process* processes) = 0;
	virtual void AddToRDY(Process* p)=0;
	virtual void RemoveProcess(Process* p)=0;
	virtual void printStats() = 0;
	void tick();
	virtual int getCurrentTime() const;
	virtual int getidealtime()=0;
	virtual int getbusytime()=0;
	virtual void setidealtime(int ideal)=0;
	virtual void setbusytime(int busy)=0;
};

