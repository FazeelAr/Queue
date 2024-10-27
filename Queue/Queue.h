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
	int noOfElements;
	void reSize(int newSize);
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
	int getNoOfElements()const;
	~Queue();
};
template<typename T>
void Queue<T>::reSize(int newSize)
{
	if (newSize <= 0)
	{
		return;
	}
	T* temp = new T[newSize];
	int i = 0;
	while (i < newSize && i < size)
	{
		temp[i] = data[i];
		i++;
	}
	if(data)
		delete []data;
	data = temp;
	size = newSize;
}
template<typename T>
int Queue<T>::getNoOfElements()const
{
	return noOfElements;
}
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
		noOfElements = 0;
		return;
	}
	size = s;
	data = new T[size];
	rear = front = -1;
	noOfElements = 0;
}
template<typename T>
bool Queue<T>::isEmpty()const
{
	return (front == -1) ? true : false;
}
template<typename T>
bool Queue<T>::isFull()const
{
	return (noOfElements==size) ? true : false;
}
template<typename T>
T Queue<T>::showFront()const
{
	if (!isEmpty())
	{
		T element = data[front%size];
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
	if (isFull())
	{
		reSize(size + 1);
	}
	rear = (rear + 1) % size;;
	data[rear] = element;
	if (front == -1)
	{
		front = 0;
	}
	noOfElements++;
}
template<typename T>
T Queue<T>::dequeue()
{
	if (!isEmpty())
	{
		front = front % size;
		T element = data[front];
		if (front == rear)
		{
			front = rear = -1;
		}
		else
		{
			front++;
		}
		noOfElements--;
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
