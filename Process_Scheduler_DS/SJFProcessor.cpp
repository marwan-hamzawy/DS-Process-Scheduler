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
//here the schedule algo will select the waiting process with the shortest cpu time to execute next
void SJFProcessor::ScheduleAlgo(Process* p)
{
    if (!Run) {
        if (!RDY.empty())
        {

        }
    }

}

