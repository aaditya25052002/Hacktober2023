// leetcode solution: https://leetcode.com/problems/design-circular-queue/

#include<iostream>
using namespace std;

class Queue
{
    int size;
    int front;
    int rear;
    int *q;
  public:
    Queue()
    {
        cout<<"Enter size of queue: ";
        cin>>size;
        q = new int[size];
        front = rear = -1;
    }
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};

bool Queue::isFull()
{
    if (front == 0 && rear == size - 1) {
      return true;
    }
    if (front == rear + 1) {
      return true;
    }
    return false;
}

bool Queue::isEmpty()
{
    if (front == -1) {
      return true;
    }
    return false;
}

void Queue::enqueue(int x)
{
    if(isFull())
    {
        cout<<"Queue is Full."<<endl;
    }
    else
    {
        if(front == -1)
            front = 0;
        rear = (rear+1)%(size);
        q[rear] = x;
    }
}

int Queue::dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue is Empty."<<endl;
        return -1;
    }
    else
    {
        int x = q[front];
        if (front == rear) 
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front+1)%size;
      // Q has only one element,
      // so we reset the queue after deleting it.
        return x; 
    }
}

void Queue::display()
{
    int i;
    for(i=front; i!=rear; i=(i+1)%(size))
        cout<<q[i]<<", ";
    cout<<q[i]<<endl;
}

int main()
{
    Queue q;
    int ch, x;
    do
    {
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1: cout<<"Enter element: ";
                    cin>>x;
                    q.enqueue(x);
                    break;
            case 2: cout<<q.dequeue()<<" was removed."<<endl;
                    break;
            case 3: q.display();
                    break;
            case 4: return 0;
        }
        cout<<endl<<endl;
    } while (ch!=4);
    
    return 0;
}