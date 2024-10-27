#include"Queue.h"
int main()
{
	try
	{
		Queue<int> q{ 7 };
		for (int i = 1; i <= 7; i++)
		{
			q.enqueue(i);
		}
		for (int i = 0; i < q.getSize()-4; i++)
		{
			q.dequeue();
			q.enqueue(i);
		}
		while(!q.isEmpty())
		{
			cout<<q.dequeue()<<' ';
		}
	}
	catch (const char* str)
	{
		cout << str;
	}

}