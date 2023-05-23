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
	p->setporcessorid(id);
}

void RRProcessor::RemoveProcess()
{
	RDY.dequeue();
}

int RRProcessor::UpdateRandomNum(Process*& p) {
	return 0;

}

void RRProcessor::ScheduleAlgo(Process* p)
{
	Process* x = RDY.dequeue();
	

}
void RRProcessor::PrintProcessor() {
    RDY.Display();
}
void RRProcessor::RemoveProcess(Process* p) {
    RDY.dequeue();
}

int RRProcessor :: ShortSizeFCFS(){
	return 0;
}
