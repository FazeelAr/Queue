#ifndef SCHEDULAR_H
#define SCHEDULAR_H
#include"Process.h"
class Schedular
{
	Process* processArray;
	int processArrayLength;
	int timeQuantam;
public:
	Schedular(Process* p, int length, int time)
	{
		processArray = p;
		processArrayLength = length;
		timeQuantam = time;
	}
	void assignProcess()
	{

	}
};
#endif // !SCHEDULAR_H
