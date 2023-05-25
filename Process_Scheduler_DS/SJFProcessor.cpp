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
void SJFProcessor::AddToRDY(Process* p)
{
	RDY.enqueue(p,p->KillTime);
	p->setporcessorid(id);
}

void SJFProcessor::RemoveProcess(Process* p)
{
	RDY.dequeue();
}




int SJFProcessor ::UpdateRandomNum(Process*& p){
	return 0;
}
void SJFProcessor ::PrintProcessor() {
    RDY.Display();
}

void SJFProcessor::ScheduleAlgo(Process* p)
{
    if(Run)
    {
        if(Run->getRemainingTime() == 0)
        {
            RemoveProcess(Run);
            Run = nullptr;
        } else{
            Run->setRemainingTime(Run->getRemainingTime() - 1);
        }
    }
    else
    {
        if(!RDY.empty())
        {
            Process* shortestProcess = RDY.getFront();
            Process* currentProcess = RDY.getNext();
            while (currentProcess) {
                if (currentProcess->getRemainingTime() < shortestProcess->getRemainingTime()) {
                    shortestProcess = currentProcess;
                }
                currentProcess = RDY.getNext();
            }

            Run = shortestProcess;
            RDY.removeProccess(shortestProcess);
        }
    }

}
int SJFProcessor::ShortSizeFCFS() {
	return 0;
}


