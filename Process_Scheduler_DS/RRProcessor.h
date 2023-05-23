#pragma once
#include"Processor.h"
#include"CircularQueue.h"
class RRProcessor:public Processor
{
private:

    RRProcessor(int numProcesses, int ts);

    CircularQueue<Process*, 100> RDY;
	int time_slice;
    int idealtime;
public:
	
	RRProcessor(int ts);
//	virtual void AddToRDY(Process* p);
	virtual void RemoveProcess();
	void ScheduleAlgo(Process* p) override;
	virtual int getidealtime();
	virtual int getbusytime();
	virtual void setidealtime(int ideal);
	virtual void setbusytime(int busy);
	int UpdateRandomNum(Process*& p) override;
    void AddToRDY(Process* p);
    void PrintProcessor() override;
    void RemoveProcess(Process* p) override;
	int ShortSizeFCFS() override;

};

