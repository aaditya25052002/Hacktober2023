/*
  There are two ways of implementing priority queue:
  1. Insert normally and delete the minimum element
  2. Insert in increasing order and delete from front

  Here we have implemented the first way
*/

#include<iostream>
using namespace std;

class PriorityQueue
{
    int size;
    int rear;
    int *q;
  public:

    PriorityQueue(int sz)
    {
      size = sz;
      rear = 0;
      q = new int[size];
    }

    bool isEmpty();
    bool isFull();
    int index_minimum();
    void enqueue(int x);
    int dequeue();
};

bool PriorityQueue::isEmpty()
{
  return (rear == 0);
}

bool PriorityQueue::isFull()
{
  return (rear == size);
}

void PriorityQueue::enqueue(int x)
{
  if(isFull())
  {
    cout<<"Queue is Full"<<endl;
    return;
  }
  q[rear++] = x;
}

int PriorityQueue::index_minimum()
{
  int res = 0;
  for(int i=1; i<rear; i++)
  {
    if(q[i]<q[res])
      res = i;
  }
  return res;
}

int PriorityQueue::dequeue()
{
  int x = -1, i;
  if(isEmpty())
    cout<<"Queue is Empty"<<endl;
  else
  {
    i = index_minimum();
    x = q[i];
    for(; i<rear-1; i++)
    {
      q[i] = q[i+1];
    }
    rear--;
  }
  return x;
}

int main()
{
  PriorityQueue q(10);
  q.enqueue(6);
  q.enqueue(8);
  q.enqueue(3);
  q.enqueue(10);
  q.enqueue(15);
  q.enqueue(2);
  q.enqueue(9);
  q.enqueue(17);
  q.enqueue(5);
  q.enqueue(8);

  for(int i=0; i<10; i++)
    cout<<q.dequeue()<<", ";
  cout<<endl;
  return 0;
}