#pragma once
#include<iostream>
using namespace std;

class Process
{
private:
	int PId; //process id
	int AT; //Arrival time
	int CT; //CPU Time
	int NIO; // number of io operations
    int* ioTimes; // array to store IO operation times
    int* ioDurations; // array to store IO operation durations
    int ioIndex; // index of the current IO operation
    int turnedroundtime;
    int waitingtime;
    int forkprop; //Fork probability 
    int priority; // priority level
    int timeRemaining; // remaining CPU time
    int STL; //Steal time
    int terminationtime;
    Process* child;
   
    
    int RTF;  //for process migration (round robin list)
    int MaxW; //maximum wait time
	int NF; //number of FCFS processors
	int NS; //number of SJF processors
	int NR; //number of RR processors
	int TimeSlice; //Time slice for RR

   
    
public:
    int KillTime;
    int currentprocessorid;
    Process (int pid, int arrivalTime, int KillTime, int numIoOps, int* ioTimes, int* ioDurations);
	~Process();
    // getters and setters for data members
    int getPid() const;
    int getArrivalTime() const;
    int getNumIoOps() const;
    int getIoIndex() const;     
    int getIoTime(int index) const;
    int getIoDuration(int index) const; 
    friend ostream& operator << (ostream& COUT, Process* p);
    void setchild(Process* p);
    Process* getchild();
    Process* next; // pointer to the next process in the ready queue
    bool allIoOpsCompleted() const;// function to check if process has completed all IO operations
    int getremaintime();
    void setporcessorid(int id);
    int getprocessorid();
    int getwaitingtime();
    int getterminationtime();
    void setterminationtime(int tm);
    int getturnroundtime();
    void setturnroundtime();
    int getCT();

};

