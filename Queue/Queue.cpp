#include"Queue.h"
#include<list>
int main()
{
	try
	{
		Queue<int> q{ 7 };
		for (int i = 1; i <= 7; i++)
		{
			q.enqueue(i);
		}
		for (int i = 0; i < q.getSize(); i++)
		{
			q.enqueue(q.dequeue());
		}
		for (int i = 1; i <= 7; i++)
		{
			cout<<q.dequeue()<<' ';
		}
	}
	catch (const char* str)
	{
		cout << str;
	}

}