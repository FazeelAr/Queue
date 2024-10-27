#include"Deque.h"
int main()
{
	try
	{
		//Queue<int> q{};
		//for (int i = 1; i <= 10; i++)
		//{
		//	q.enqueue(i);
		//}
		////cout << "ggv";
		//for (int i = 0; i < q.getSize()-4; i++)
		//{
		//	q.dequeue();
		//	q.enqueue(i);
		//}
		//while(!q.isEmpty())
		//{
		//	cout<<q.dequeue()<<' ';
		//}
		Deque<int> deck{ 5 };
		for (int i = 0; i < 5; i++)
		{
			deck.insertAtTail(i + 1);
		}
		cout << deck.deleteAtTail() << '\n';
		cout << deck.deleteAtHead() << '\n';
		cout << deck.deleteAtHead() << '\n';
		deck.insertAtHead(6);
		cout << deck.deleteAtHead() << '\n';

	}
	catch (const char* str)
	{
		cout << str;
	}

}