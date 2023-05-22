#include "FCFSProcessor.h"
#include"Queue.h"
#include"Process.h"
#include "Scheduler.h"
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

//function to get the lenght of the fcfs processor to know the while number of the cpu time of that processor
//return data type of int

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

void FCFSProcessor::ScheduleAlgo(Process* p, Scheduler* s) {
    //if the process is done
//    if (p->getRemainingTime() == 0) {
//        //if the process is done
//        s->TerminateProcess(p);
//    }
//    else {
//        //if the process is not done
//        s->AddToReadyQueue(p);
//    }
//};


//implemetation of the fcfs scheduling algorithm
//-TODO
//1- Service the running process if there is one
//2- Decides whether to send the running process to the blocked queue or the ready queue or terminate it or keep it running
//3- If no process is running, it will get the next process from the ready queue and run it
if (Run) {
    //check if the process has I/O
    if(p->getNumIoOps() > 0){
        s->addtoBLK(p);
    }
    else {
        //if the process does not have I/O burst
        RDY.EnQueue(p);
    }

    //if the process is running decide whether to send it to the blocked queue or the ready queue or terminate it or keep it running
    if (Run->getRemainingTime() == 0) {
        //if the process is done
        Run = nullptr;
        s->terminateProcess(p);
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

