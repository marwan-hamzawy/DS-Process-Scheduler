#pragma once
#include"Process.h"
#include"Scheduler.h"
class Processor
{
private:
	
	int numProcesses; // number of processes in the ready queue
	double current_time;

	

public:
	int idealtime;
	int busytime;
	
	Process* Run = nullptr;

	Processor(int numProcesses);
    virtual void ScheduleAlgo(Process* p, Scheduler* s) = 0;
	virtual void AddToRDY(Process* p)=0;
	virtual void RemoveProcess(Process* p)=0;
	//virtual void printStats() = 0;
	void tick();
	int getCurrentTime() const;
	virtual int getidealtime()=0;
	virtual int getbusytime()=0;
	virtual void setidealtime(int ideal)=0;
	virtual void setbusytime(int busy)=0;
	virtual int UpdateRandomNum(Process*& p) =0;
	virtual void PrintProcessor() = 0;
	Process* getRun() const;
};

