#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class queue
{
private:
    node *front;
    node *rear;
public:
    queue();
    void enqueue(int x);
    int dequeue();
    void display();
};
queue::queue()
{
    front=rear=NULL;
}
void queue::enqueue(int x)
{
    node *t=new node;
    t->data=x;
    t->next=NULL;
    if(front==NULL)
     front=rear=t;
    else
    {
        rear->next=t;
        rear=t;
    }
}
int queue::dequeue()
{
    int x=-1;
    if(front==NULL)
    {
        cout<<"Queue is empty"<<endl;
        return x;
    }
    else
    {
        node *t=front;
        front=front->next;
        x=t->data;
        delete []t;
        return x;
    }
}
void queue::display()
{
    if(front==NULL)
     cout<<"Queue is empty"<<endl;
    else
    {
        node *t=front;
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
    }
}
int main()
{
    queue que;
    que.enqueue(1);
    que.enqueue(2);
    que.enqueue(3);
    que.enqueue(4);
    que.enqueue(5);
    que.dequeue();
    que.dequeue();
    que.enqueue(7);
    que.enqueue(8);
    que.enqueue(9);
    que.dequeue();
    que.display();
}