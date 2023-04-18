#include "SJFProcessor.h"

SJFProcessor::SJFProcessor(int numProcesses):Processor(numProcesses)
{
}
int SJFProcessor::getidealtime()
{
	return idealtime;
}

int SJFProcessor::getbusytime()
{
	return busytime;
}

void SJFProcessor::setidealtime(int ideal)
{
	idealtime = ideal;
}

void SJFProcessor::setbusytime(int busy)
{
	busytime = busy;
}
int SJFProcessor::getCurrentTime() const
{
    return current_time;
}
void SJFProcessor::AddToRDY(Process* p)
{
	RDY.enqueue(p,p->KillTime);
}

void SJFProcessor::RemoveProcess()
{
	RDY.dequeue();
}

void SJFProcessor::ScheduleAlgo(Process* p)
{
    // Check if RDY queue is empty
    if (RDY.empty()) {
        return;
    }
	else
	{
		Run = RDY.dequeue();
	}

 
 }

