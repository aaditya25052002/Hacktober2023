#include<iostream>
using namespace std;

class Node
{
  public:
    int val;
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
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x)
{
    Node *t = new Node;
    if(t==NULL)
    {
        cout<<"Queue is Full."<<endl;
        return;
    }

    t->val = x;
    if(front == NULL)
    {
        front = rear = t;
    }
    else
    {
        rear->next = t;
        rear = t;
    }
}

int Queue::dequeue()
{
    int x=-1;
    Node *p = front;
    if(front==NULL)
    {
        cout<<"Queue is Empty."<<endl;
    }
    else
    {
        x = p->val;
        front = front->next;
        delete p;
    }
    return x;
}

void Queue::display()
{
    Node *p = front;
    while(p)
    {
        cout<<p->val<<", ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    Queue q;
    int ch, x;

    do
    {
        cout<<"1. Insert"<<endl;
        cout<<"2. Remove"<<endl;
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