#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
    char val;
    Node *next;

    Node()
    {
      val = 0;
      next = NULL;
    }
};

class Queue
{
    Node *front;
    Node *rear;
  
  public:
    Queue()
    {
      front = rear = NULL;
    }
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
};

bool Queue::isEmpty()
{
  return front==NULL;
}

void Queue::enqueue(int x)
{
  Node *t = new Node;
  if(t==NULL)
  {
    cout<<"Queue is Full."<<endl;
    return;
  }
  t->val = x;

  if(front==NULL)
    front = rear =t;
  else
  {
    rear->next = t;
    rear = t;
  }
}

int Queue::dequeue()
{
  int x = -1;
  if(isEmpty())
    cout<<"Queue is Empty"<<endl;
  else
  {
    Node *p = front;
    x = front->val;
    front = front->next;
    delete p;
  }  
  return x;
}

int main()
{
  unordered_map<char, int> priorities;
  priorities['A'] = 1;
  priorities['B'] = 1;
  priorities['C'] = 2;
  priorities['D'] = 3;
  priorities['E'] = 2;
  priorities['F'] = 1;
  priorities['G'] = 2;
  priorities['H'] = 3;
  priorities['I'] = 2;
  priorities['J'] = 2;

  Queue q[3];

  char element[] = {'A','B','C','D','E','F','G','H','I','J'};

  for(int i=0; i<10; i++)
  {
    q[priorities[element[i]]-1].enqueue(element[i]);
  }

  for(int i=0; i<10; i++)
  {
    char x;
    if(!q[0].isEmpty())
      x=q[0].dequeue();
    else if(!q[1].isEmpty())
      x=q[1].dequeue();
    else if(!q[2].isEmpty())
      x=q[2].dequeue();
    else
    {
      cout<<"Queues are Empty"<<endl;
      break;
    }

    cout<<x<<", ";
  }
  cout<<endl;
  return 0;
}