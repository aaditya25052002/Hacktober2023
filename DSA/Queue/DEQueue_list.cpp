#include<iostream>
using namespace std;

class Node
{
  public:
    int val;
    Node* next;

    Node()
    {
      val = 0;
      next = NULL;
    }
};

class DEQueue
{
  public:
    Node *front;
    Node *rear;

    DEQueue()
    {
      front = rear = NULL; 
    }
    void insert_rear(int x);
    void insert_front(int x);
    int remove_rear();
    int remove_front();
    void display();
};

void DEQueue::display()
{
  Node *p=front;
  while(p)
  {
    cout<<p->val<<", ";
    p=p->next;
  }
  cout<<endl;
}

void DEQueue::insert_front(int x)
{
  Node *t = new Node;
  if(t == NULL)
  {
    cout<<"Queue is Full."<<endl;
    return;
  }

  t->val = x;
  if(front == NULL)
    front = rear = t;
  else
  {
    t->next = front;
    front = t;
  }
}

void DEQueue::insert_rear(int x)
{
  Node *t = new Node;
  if(t == NULL)
  {
    cout<<"Queue is Full."<<endl;
    return;
  }

  t->val = x;
  if(front == NULL)
    front = rear = t;
  else
  {
    rear->next = t;
    rear = t;
  }
}

int DEQueue::remove_front()
{
  int x = -1;
  if(front == NULL)
  {
    cout<<"Queue is Empty"<<endl;
  }
  else
  {
    Node *p = front;
    x = front->val;
    front = front->next;
    delete p;
  }

  return x;
}

int DEQueue::remove_rear()
{
  int x = -1;
  if(front == NULL)
  {
    cout<<"Queue is Empty"<<endl;
  }
  else
  {
    Node *p = front;
    Node *q = NULL;

    while(p != rear)
    {
      q=p;
      p=p->next;
    }

    if(q==NULL)
      front = rear = NULL;
    else
      rear = q;
    x = p->val;
    delete p;
  }
  return x;
}


int main()
{
    DEQueue Q;
    int ch, x;
    do
    {
      cout<<"1. Insert front"<<endl;
      cout<<"2. Insert rear"<<endl;
      cout<<"3. Delete front"<<endl;
      cout<<"4. Delete rear"<<endl;
      cout<<"5. Display"<<endl;
      cout<<"6. Exit"<<endl;
      cin>>ch;

      switch(ch)
      {
        case 1: cout<<"Enter element: ";
                cin>>x;
                Q.insert_front(x);
                break;
        case 2: cout<<"Enter element: ";
                cin>>x;
                Q.insert_rear(x);
                break;
        case 3: cout<<Q.remove_front()<<" was removed"<<endl;
                break;
        case 4: cout<<Q.remove_rear()<<" was removed"<<endl;
                break;
        case 5: Q.display();
                break;
        case 6: return 0;
      }
      cout<<endl<<endl;
    } while (ch!=6);
    
    return 0;
}