#include "FCFSProcessor.h"
#include"Queue.h"
#include <cstdlib>

FCFSProcessor::FCFSProcessor(int numProcesses) :Processor(numProcesses) {}

FCFSProcessor::FCFSProcessor() :Processor(5) {

}


void FCFSProcessor::AddToRDY(Process* p)
{
	RDY.EnQueue(p);
}

void FCFSProcessor::RemoveProcess(Process* p)
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

//void FCFSProcessor::printStats() {}
	
int FCFSProcessor::UpdateRandomNum(Process* p) {
	if (!Run) {
		p = RDY.DeQueue();
		//RDY.DeQueue()
	}
	int randomNumber = rand() % 3;   // generate a random integer between 0 and 2
	if (randomNumber == 0) {

	}
	else if (randomNumber == 1 || randomNumber == 2) {
		Run = nullptr;
	}

	return randomNumber;                // return the random number

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

void FCFSProcessor::PrintProcessor() {
	RDY.Display();
 
}

