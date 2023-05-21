#include "Processor.h"

Processor::Processor(int numProcesses) : numProcesses(numProcesses)
{
	busytime = 0;
	idealtime = 0;
	
}

void Processor::tick()
{
	current_time++;
}

int Processor::getCurrentTime() const
{
	
		return current_time;
	
}

Process* Processor :: getRun() const
{
	return Run;
}

int Processor::getprocessorid()
{
	return 0;
}

//int Processor::getidealtime()
//{
//	return idealtime;
//}
//
//int Processor::getbusytime()
//{
//	return busytime;
//}
//
//void Processor::setidealtime(int ideal)
//{
//	idealtime = ideal;
//}
//
//void Processor::setbusytime(int busy)
//{
//	busytime = busy;
//}
