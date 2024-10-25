#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
using namespace std;
template<typename T>
class Queue
{
	T* data;
	int size;
	int front;
	int rear;
public:
	Queue(int s = 0);
	int getSize()const;
	bool isEmpty()const;
	bool isFull()const;
	T showFront()const;
	T showRear()const;
	void enqueue(T element);
	T dequeue();
	T shiftedDequeue();
	void printQueue();
	~Queue();
};
template<typename T>
int Queue<T>::getSize()const
{
	return size;
}
template<typename T>
Queue<T>::Queue(int s)
{
	if (s <= 0)
	{
		data = nullptr;
		size = 0;
		rear = front = -1;
		return;
	}
	size = s;
	data = new T[size];
	rear = front = -1;
}
template<typename T>
bool Queue<T>::isEmpty()const
{
	return (front == -1) ? true : false;
}
template<typename T>
bool Queue<T>::isFull()const
{
	return (front == (rear + 1) % size) ? true : false;
}
template<typename T>
T Queue<T>::showFront()const
{
	if (!isEmpty())
	{
		T element = data[front];
		return element;
	}
	else
	{
		throw "\nQueue is empty:";
	}
}
template<typename T>
T Queue<T>::showRear()const
{
	if (!isEmpty())
	{
		T element = data[rear];
		return element;
	}
	else
	{
		throw "\nQueue is empty:";
	}
}
template<typename T>
void Queue<T>::enqueue(T element)
{
	if (!isFull())
	{
		rear = (rear + 1) % size;
		data[rear] = element;
		if (front == -1)
		{
			front = 0;
		}
	}
	else
	{
		throw "\nQueue is full";
	}
}
template<typename T>
T Queue<T>::dequeue()
{
	if (!isEmpty())
	{
		front = front % size;
		T element = data[front%size];
		if (front == rear)
		{
			front = rear = -1;
		}
		else
		{
			front++;
		}
		return element;
	}
	else
	{
		throw "\nQueue is Empty:";
	}
}
template<typename T>
T Queue<T>::shiftedDequeue()
{
	if (!isEmpty())
	{
		T element = data[front];
		for (int i = 0; i < rear; i++)
		{
			data[i] = data[i + 1];
		}
		rear--;
		if (front == rear)
		{
			front = rear = -1;
		}
		return element;
	}
	else
	{
		throw "\nQueue is Empty:";
	}
	
}
template<typename T>
void Queue<T>::printQueue()
{
	cout << '\n';
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << ' ';
	}
}
template<typename T>
Queue<T>::~Queue()
{
	if (!data)
	{
		return;
	}
	delete[]data;
	size = 0;
	rear = -1;
	front = -1;
}

#endif // !QUEUE_H
