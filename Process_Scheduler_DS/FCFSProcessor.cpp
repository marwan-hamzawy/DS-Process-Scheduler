#include "FCFSProcessor.h"
#include"Queue.h"
#include <cstdlib>

FCFSProcessor::FCFSProcessor(int numProcesses) :Processor(numProcesses) {}

FCFSProcessor::FCFSProcessor() :Processor(5) {

}


void FCFSProcessor::AddToRDY(Process* p)
{
	RDY.EnQueue(p);
	p->setporcessorid(id);
}

void FCFSProcessor::RemoveProcess(Process* p)
{
	RDY.DeQueue();
}

void FCFSProcessor::RemoveProcess2(Process* p)
{
	RDY.removeitem(p);
	
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
	
int FCFSProcessor::UpdateRandomNum(Process*& p) {
	if (!Run) {
		if (!RDY.IsEmpty())
		{
			Run = RDY.DeQueue();
			//RDY.DeQueue()
		}
	}
	p = Run;
	int randomNumber = rand()%15;   // generate a random integer between 0 and 2

	if (randomNumber == 1 || randomNumber == 2) {
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

bool FCFSProcessor::forkrequired(Process*& p,int fk,int at,int num)
{
	if (Run) {
		srand(time(0)); // Use current time as the seed

		// Generate a random number from 0 to 100
		int randomNumber = rand() % 101;
		if (randomNumber < fk) 
		{
			int cpu = Run->getremaintime();
			Process* fp = new Process(num + 1, at, 0, 0, nullptr, nullptr);
			p = fp;
			Run->setchild(fp);
			return true;

		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

