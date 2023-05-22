#include "FCFSProcessor.h"
#include"Queue.h"
#include"Scheduler.h"
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

//function to get the length of the fcfs processor to know the while number of the cpu time of that processor
//return data type of int
int FCFSProcessor::ShortSizeFCFS() {
	//int totalCPUTime = 0;

	//Process* currentItem = RDY.FRONT();  // Get the front item of the linked list

	//// Iterate over the linked list until the end
	//while (currentItem != nullptr) {
	//	totalCPUTime += currentItem->getCPUtime();
	//	currentItem = currentItem->getNext();  // Move to the next item (assuming you have a getNext() function in your Process class)
	//}

	//return totalCPUTime;

	int totalCPUTime = 0;

	Node1<Process*>* currentNode = RDY.getFront();  // Get the front node of the linked list

	// Iterate over the linked list until the desired index
	for (int i = 0; i < RDY.Size(); i++) {
		Process* p = currentNode->getItem();
		totalCPUTime += p->getCPUtime();
		currentNode = currentNode->getNext();  // Move to the next node
	}

	return totalCPUTime;
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

	// in the if statement we would check if the CPUtime == 0
	if (Run) {
		p->Execute();					//Here we chould make a function ""Execute" that 

		if (p->getCPUtime() == 0) {
			Run = nullptr;
			return 1;
		}

		if (p->ifneedIO()) {
			Run = nullptr;
			return 2;
		}
	}

	return 0;
}

void FCFSProcessor::ScheduleAlgo(Process* p)
{
    if (Run) {

        //check if the process has I/O
//        if(p->getNumIoOps() > 0){
//            s->addtoBLK(p);
//        }
//        else {
//            //if the process does not have I/O burst
//            RDY.EnQueue(p);
//        }

        //if the process is running decide whether to send it to the blocked queue or the ready queue or terminate it or keep it running
        if (Run->getRemainingTime() == 0) {
            //if the process is done
            Run = nullptr;
        }
        else {
            //if the process is not done
            Run->setRemainingTime(Run->getRemainingTime() - 1);

        }
    }
    else {
        //if there is no process running
        if (!RDY.IsEmpty()) {
            //if the ready queue is not empty
            Run = RDY.DeQueue();
            Run->setRemainingTime(Run->getRemainingTime() - 1);
        }
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

