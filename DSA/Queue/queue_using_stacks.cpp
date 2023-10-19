#include<iostream>
using namespace std;

class Stack
{
  public:
    int size;
    int top;
    int *s;

    Stack(int sz)
    {
      size = sz;
      top = -1;
      s = new int[size];
    }

    bool isFull()
    {
      return (top == size);
    }

    bool isEmpty()
    {
      return (top == -1);
    }

    void push(int x)
    {
      if(isFull())
        cout<<"Stack is Full."<<endl;
      else
        s[++top] = x;
    }

    int pop()
    {
      int x = -1;
      if(isEmpty())
      {
        cout<<"Stack is Empty."<<endl;
      }
      else
      {
        x = s[top--];
      }
      return x;
    }
};

class Queue
{
    Stack *s1;
    Stack *s2;
  public:
    Queue()
    {
      s1 = new Stack(10);
      s2 = new Stack(10);
    }

    void enqueue(int x)
    {
      s1->push(x);
    }

    int dequeue()
    {
      int x = -1;
      if(s2->isEmpty())
      {
        if(s1->isEmpty())
        {
          cout<<"Queue is Empty."<<endl;
          return x;
        }
        else
        {
          while(!s1->isEmpty())
            s2->push(s1->pop());
        }
      }
      return s2->pop();
    }
};

int main()
{
  Queue q;
  q.enqueue(6);
  q.enqueue(3);
  q.enqueue(9);
  q.enqueue(5);
  q.enqueue(4);
  q.enqueue(2);
  q.enqueue(8);
  q.enqueue(12);
  q.enqueue(10);
  q.enqueue(7);

  for(int i=0; i<10; i++)
    cout<<q.dequeue()<<", ";
  cout<<endl;
  return 0;
}