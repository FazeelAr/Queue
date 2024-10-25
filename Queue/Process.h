#ifndef PROCESS_H
#define PROCESS_H
#include"Queue.h"
class Process
{
	int processID;
	string processName;
	int processAcessTime;
public:
	Process(int id = 1, string pNAme = "notepad", int burstTime = 10)
	{
		processID = id;
		processName = pNAme;
		processAcessTime = burstTime;
	}
	void setProcessID(int proID)
	{
		processID = proID;
	}
	void setProcessName(string name)
	{
		processName = name;
	}
	int getProcessID()const
	{
		return processID;
	}
	string getProcessName()const
	{
		return processName;
	}
};
#endif // !PROCESS_H
