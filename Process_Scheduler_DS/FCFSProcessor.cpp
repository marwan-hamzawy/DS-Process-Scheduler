#include "FCFSProcessor.h"
#include"Queue.h"

FCFSProcessor::FCFSProcessor(int numProcesses) :Processor(numProcesses) {}

void FCFSProcessor::AddToRDY(Process* p)
{
	RDY.EnQueue(p);
}

void FCFSProcessor::RemoveProcess()
{
	RDY.DeQueue();
}



int FCFSProcessor::getidealtime()
{
	return idealtime;
}

int FCFSProcessor::getbusytime()
{
	return busytime;
}

void FCFSProcessor::setidealtime(int ideal)
{
	idealtime = ideal;
}

void FCFSProcessor::setbusytime(int busy)
{
	busytime = busy;
}


void FCFSProcessor::ScheduleAlgo(Process* p)
{
	if (Run != nullptr) {
		setbusytime(busytime++);
	}
	if (Run = nullptr) {
		setidealtime(idealtime++);
	}
	if (!RDY.IsEmpty()) {
		Process* p = RDY.FRONT();
		RDY.DeQueue();
		RDY.EnQueue(p);

	}

}
