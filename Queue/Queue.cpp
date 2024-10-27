#include"Queue.h"
#include<stack>
class MyQueue
{
public:
    stack<int> s;
    MyQueue()
    { }

    void push(int x)
    {
        s.push(x);
    }

    int pop()
    {
        if (!s.empty())
        {
            stack<int> temp;
            cout <<"SIZE: " << s.size() <<'\n';
            while(!s.empty())
            {
                temp.push(s.top());
                s.pop();
            }
            while (!temp.empty())
            {
                cout<<(temp.top())<<'\n';
                temp.pop();
            }
            int element = temp.top();
            temp.pop();
            while (!temp.empty())
            {
                s.push(temp.top());
                temp.pop();
            }
            return element;
        }
        return -1;
    }

    int peek()
    {
        if (!s.empty())
        {
            stack<int> temp;
            while (!s.empty())
            {
                temp.push(s.top());
                s.pop();
            }
            int element = temp.top();
            //temp.pop();
            while (!temp.empty())
            {
                s.push(temp.top());
                temp.pop();
            }
            return element;
        }
        return -1;
    }

    bool empty()
    {
        return s.empty();
    }
};

int main()
{
 //Your MyQueue object will be instantiated and called as such:
     MyQueue* obj = new MyQueue();
     obj->push(1);
     obj->push(2);
     obj->push(3);
     obj->push(4);
     cout << obj->s.size()<<'\n';
     for (int i = 0; i < obj->s.size(); i++)
     {
         cout << obj->s.top() << '\n';
         obj->s.pop();
     }
}
//int main()
//{
//	try
//	{
//		Queue<int> q{ 7 };
//		for (int i = 1; i <= 7; i++)
//		{
//			q.enqueue(i);
//		}
//		for (int i = 0; i < q.getSize(); i++)
//		{
//			q.enqueue(q.dequeue());
//		}
//		for (int i = 1; i <= 7; i++)
//		{
//			cout<<q.dequeue()<<' ';
//		}
//	}
//	catch (const char* str)
//	{
//		cout << str;
//	}
//
//}