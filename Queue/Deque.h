#ifndef DEQUE_H
#define DEQUE_H
#include"Queue.h"
template<typename T>
class Deque
{
	T* data;
	int noOfElements;
	int capacity;
	int front;
	int rear;
	void reSize(int newSize)
	{
		if (newSize <= 0)
		{
			return;
		}
		T* temp = new T[newSize];
		int i = 0;
		while (i < newSize && i < capacity)
		{
			temp[i] = data[i];
			i++;
		}
		if (data)
			delete[]data;
		data = temp;
		capacity = newSize;
	}
public:
	Deque(int s = 0)
	{
		if (s <= 0)
		{
			data = nullptr;
			capacity = 0;
			rear = front = -1;
			noOfElements = 0;
			return;
		}
		capacity = s;
		data = new T[capacity];
		rear = front = -1;
		noOfElements = 0;
	}
	bool isFull()
	{
		return (noOfElements == capacity);
	}
	bool isEmpty()
	{
		return (rear == -1 && front == -1);
	}
	void insertAtHead(T element)
	{
		if (!isFull()&&front > 0)
		{
			data[front - 1] = element;
			front--;
		}
		else
		{
			cout << "Queue is full:";
		}
	}
	void insertAtTail(T element)
	{
		if (isFull())
		{
			reSize(capacity + 1);
		}
		rear = rear + 1;
		data[rear] = element;
		if (front == -1)
		{
			front = 0;
		}
		noOfElements++;
	}
	T deleteAtTail()
	{
		if (!isEmpty())
		{
			T element = data[rear];
			if (front == rear)
			{
				front = rear = -1;
			}
			else
			{
				rear--;
			}
			noOfElements--;
			return element;
		}
		else
		{
			throw "\nQueue is Empty:";
		}
	}
	T deleteAtHead()
	{
		if (!isEmpty())
		{
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
};
#endif // !DEQUE_H
