#include "Process.h"

Process::Process(int pid, int arrivalTime, int KillTime, int numIoOps, int* ioTimes, int* ioDurations) : PId(pid),
AT(arrivalTime), KillTime(KillTime),ioIndex(0), NIO(numIoOps), ioTimes(new int[numIoOps]),
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

void Process::setchild(Process* p)
{
    child = p;
}

Process* Process::getchild()
{
    return child;
}



bool Process::allIoOpsCompleted() const
{
    return ioIndex >= NIO;
}
int Process::getremaintime()
{
    return timeRemaining;
}
void Process::setporcessorid(int id)
{
    currentprocessorid = id;
}
int Process::getprocessorid()
{
    return currentprocessorid;
}
 ostream& operator << (ostream& COUT, Process* p) {
     COUT << p->getPid() << "    ";
     return COUT;
}

