#include "Scheduler.h"

Scheduler::Scheduler(int nF, int nS, int nR, int Rs)
{
    NF = nF;
    NS = nS;
    NR = nR;
    RS = Rs;
    numProcessors = NF + NS + NR;
    processors = new Processor * [numProcessors];

}
void Scheduler::fileloading() {
    string word, t, q, filename;
    ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }
    while (file >> word)
    {


    }
//    int pid, arrivalTime, KillTime, numIoOps, *ioTimes, *ioDurations;
//    while (file >> pid >> arrivalTime >> KillTime >> numIoOps) {
//        ioTimes = new int[numIoOps];
//        ioDurations = new int[numIoOps];
//        for (int i = 0; i < numIoOps; i++) {
//            file >> ioTimes[i] >> ioDurations[i];
//        }
//        Process *p = new Process(pid, arrivalTime, KillTime, numIoOps, ioTimes, ioDurations);
//        NEW.EnQueue(p);
//    }
    file.close();
}
Scheduler::~Scheduler()
{
    delete[] processors;
}