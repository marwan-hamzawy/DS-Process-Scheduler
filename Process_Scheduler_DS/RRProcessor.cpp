#include "RRProcessor.h"

RRProcessor::RRProcessor(int numProcesses, int ts):Processor(numProcesses)
{

	time_slice = ts;
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
        if (Run != nullptr) {
            if (Run->getRemainingTime() > 0) {
                // Service the running process
                Run->setRemainingTime(Run->getRemainingTime() - 1);
                time_slice--;

                if (Run->getRemainingTime() == 0) {
                    // Process completed
                    RemoveProcess(Run);
                    Run = nullptr;
                } else if (time_slice == 0) {
                    // Time quantum expired, move the process to the end of the ready queue
                    AddToRDY(Run);
                    Run = nullptr;
                }
            }
        }

        if (Run == nullptr && !RDY.isEmpty()) {
            // Get the next process from the ready queue and start running it
            RDY.dequeue();
            Run->setRemainingTime(Run->getRemainingTime() - 1);
        }



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
