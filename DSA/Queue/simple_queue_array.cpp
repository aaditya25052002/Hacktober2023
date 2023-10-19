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

    void enqueue(int x)
    {
        if(rear==size-1)
            cout<<"Queue is full"<<endl;
        else
            q[++rear]=x;
    }

    int dequeue()
    {
        if(front==rear)
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else
            return q[++front];
    }

    void display()
    {
        for(int i=front+1; i<=rear; i++)
            cout<<q[i]<<", ";
        cout<<endl;
    }
};

int main()
{
    Queue Q;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.display();
    Q.dequeue();
    Q.dequeue();
    Q.display();
    return 0;
}