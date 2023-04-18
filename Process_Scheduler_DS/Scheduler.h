#pragma once
#include "Processor.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "FCFSProcessor.h"
#include "RRProcessor.h"
#include "SJFProcessor.h"
#include "Process.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Scheduler
{
private:

int NF; // number of FCFS processors
int NS; // number of SJF processors
int NR; // number of RR processors
int RS; // size of ready queue
int numProcessors;
string filename = "processes.txt";

Processor** processors = new Processor* [numProcessors];
Queue <Process*> NEW;
Queue <Process*> RDY;
Queue <Process*> RUN;


public:

    Scheduler(int nF, int nS, int nR, int RS);

};

