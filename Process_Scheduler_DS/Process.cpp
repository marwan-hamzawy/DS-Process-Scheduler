#include "Process.h"

Process::Process(int pid, int arrivalTime, int CT, int numIoOps, int* ioTimes, int* ioDurations) : PId(pid),
AT(arrivalTime), CT(CT),ioIndex(0), NIO(numIoOps), ioTimes(new int[numIoOps]),
 ioDurations(new int[numIoOps])
{
    for (int i = 0; i < numIoOps; i++)
    {
        this->ioTimes[i] = ioTimes[i];
        this->ioDurations[i] = ioDurations[i];
    }
}

Process::~Process()
{
    delete[] ioTimes;
    delete[] ioDurations;
}

int Process::getPid() const
{
    return PId;
}

int Process::getArrivalTime() const
{
    return AT;
}

int Process::getNumIoOps() const
{
    return NIO;
}

int Process::getIoIndex() const
{
    return ioIndex;
}

int Process::getIoTime(int index) const
{
    return ioTimes[index];
}

int Process::getIoDuration(int index) const
{
    return ioDurations[index];
}
int Process::getRemainingTime() const
{
    // Calculate the remaining time by subtracting the completed time from the total CPU time
    int completedTime = CT - getTimeLeft();
    int remainingTime = CT - completedTime;
    return remainingTime;
}
void Process::setRemainingTime(int time)
{
    CT = time;
}
int Process::getTimeLeft() const
{
    // Calculate the time left by subtracting the completed time from the total CPU time
    int completedTime = 0;
    for (int i = 0; i < ioIndex; i++)
    {
        completedTime += ioDurations[i];
    }
    int timeLeft = CT - completedTime;
    return timeLeft;
}

bool Process::allIoOpsCompleted() const
{
    return ioIndex >= NIO;
}
 ostream& operator << (ostream& COUT, Process* p) {
     COUT << p->getPid() << "    ";
     return COUT;
}

