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
int Process::getRemainingTime() const
{
    // Calculate the remaining time by subtracting the completed time from the total CPU time
    int completedTime = CT - getTimeLeft();
    int remainingTime = CT - completedTime;
    return remainingTime;
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
void Process::setRemainingTime(int time)
{
    CT = time;
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
int Process::getwaitingtime()
{
    return waitingtime;
}
int Process::getterminationtime()
{
    return  terminationtime;
}
void Process::setterminationtime(int tm)
{
    terminationtime = tm;
}
int Process::getturnroundtime()
{
    return turnedroundtime;
}
void Process::setturnroundtime()
{
    turnedroundtime = terminationtime - AT;
}
int Process::getCT()
{
    return CT;
}

 ostream& operator << (ostream& COUT, Process* p) {
     COUT << p->getPid() << "    ";
     return COUT;
}

