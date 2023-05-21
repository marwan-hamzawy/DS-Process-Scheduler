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
}


