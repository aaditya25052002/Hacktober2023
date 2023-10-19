#include<iostream>
using namespace std;

class DEQueue
{
  public:
    int size;
    int front;
    int rear;
    int *q;

    DEQueue()
    {
      cout<<"Enter size: ";
      cin>>size;
      front = 0;
      rear = 0;
      q = new int[size];
    }

    bool isEmpty();
    bool isFull();
    void insert_rear(int x);
    void insert_front(int x);
    int remove_rear();
    int remove_front();
    void display();
};

bool DEQueue::isEmpty()
{
  return front==rear;
}

bool DEQueue::isFull()
{
  if(front==(rear+1)%(size+1))
    return true;
  return false;
}

void DEQueue::insert_rear(int x)
{
  if(isFull())
  {
    cout<<"Queue is Full."<<endl;
    return;
  }
  q[rear] = x;
  rear = (rear+1)%(size+1);
}

void DEQueue::insert_front(int x)
{
  if(isFull())
  {
    cout<<"Queue is Full."<<endl;
    return;
  }
  front = front-1;
  if(front<0)
    front = size;
  q[front] = x;
}

void DEQueue::display()
{
  if(!isEmpty())
  {
    for(int i=front; i!=rear; i=(i+1)%(size+1))
      cout<<q[i]<<", ";
    cout<<endl;
  }
}

int DEQueue::remove_front()
{
  int x = -1;
  if(isEmpty())
    cout<<"Queue is Empty"<<endl;
  else
  {
    x = q[front];
    front=(front+1)%(size+1);
  }
  return x;
}

int DEQueue::remove_rear()
{
  int x = -1;
  if(isEmpty())
    cout<<"Queue is Empty"<<endl;
  else
  {
    rear=(rear-1);
    if(rear<0)
      rear = size-1;
    x = q[rear];
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