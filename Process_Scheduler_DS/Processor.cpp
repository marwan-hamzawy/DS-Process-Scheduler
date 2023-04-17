#include "Processor.h"

Processor::Processor(int numProcesses) : numProcesses(numProcesses)
{
}

void Processor::tick()
{
	current_time++;
}

int Processor::getCurrentTime() const
{
	
		return current_time;
	
}

int Processor::getidealtime()
{
	return idealtime;
}

int Processor::getbusytime()
{
	return busytime;
}

void Processor::setidealtime(int ideal)
{
	idealtime = ideal;
}

void Processor::setbusytime(int busy)
{
	busytime = busy;
}
