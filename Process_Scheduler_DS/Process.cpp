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

bool Process::allIoOpsCompleted() const
{
    return ioIndex >= NIO;
}

int Process::getCPUtime() const {
    return CT;
}
 
bool Process::ExecuteIO() {
    if (ioDurations[0] != 0) {
        ioDurations[0]--;
        return false;
    }
    else {
        for (int i = 0; i < NIO; i++) {
            ioDurations[i] = ioDurations[i + 1];
            ioTimes[i] = ioTimes[i + 1];
        }
        NIO--;
        return true;
    }
           
}

void Process::Execute() {
    CT--;                       //we here reduce the cputime with one
    runtime++;

}
bool Process::ifneedIO() {
    if (runtime == ioTimes[0])
        return true;
    else
        return false;
}

 ostream& operator << (ostream& COUT, Process* p) {
     COUT << p->getPid() << "    ";
     return COUT;
}

