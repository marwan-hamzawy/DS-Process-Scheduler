#include "RRProcessor.h"

RRProcessor::RRProcessor(int numProcesses):Processor(numProcesses)
{
}
int RRProcessor::getidealtime()
{
	return idealtime;
}

int RRProcessor::getbusytime()
{
	return busytime;
}

void RRProcessor::setidealtime(int ideal)
{
	idealtime = ideal;
}

void RRProcessor::setbusytime(int busy)
{
	busytime = busy;
}
void RRProcessor::AddToRDY(Process* p)
{
	RDY.enqueue(p);
}

void RRProcessor::RemoveProcess()
{
	RDY.dequeue();
}

void RRProcessor::ScheduleAlgo(Process* p)
{
	Process* x = RDY.dequeue();
	

}
