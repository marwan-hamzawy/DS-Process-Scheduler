#include "RRProcessor.h"

RRProcessor::RRProcessor(int numProcesses):Processor(numProcesses)
{
	
	time_slice = 0;
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

int RRProcessor::UpdateRandomNum(Process* p) {
	return 0;

}

void RRProcessor::ScheduleAlgo(Process* p)
{
	Process* x = RDY.dequeue();
	

}
