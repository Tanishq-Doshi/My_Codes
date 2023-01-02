#include<iostream>
using namespace std;
class queue
{
private:
    int size;
    int front; // index before first element
    int rear; // index at last element
    int *Q; // array
public:
    queue(int size1);
    void enqueue(int x);
    int dequeue();
    void display();  
};
queue::queue(int size1)
{
    size=size1; // effectively size becomes size - 1 in circular queue
    Q=new int[size];
    front=rear=0; // important
}
void queue::enqueue(int x)
{
    if((rear+1)%size==front) // circular queue is full (rear is just behind front)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    rear=(rear+1)%size;
    Q[rear]=x;
}
int queue::dequeue()
{
    int x=-1;
    if(front==rear) // queue is empty
    {
        cout<<"Queue is empty"<<endl;
        return x;
    }
    front=(front+1)%size;
    x=Q[front];
    Q[front]=-1;
    return x;
}
void queue::display()
{
    if(front==rear) // queue is empty
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    int i=front+1;
    do
    {
        cout<<Q[i]<<" ";
        i=(i+1)%size;
    } while(i!=(rear+1)%size);
}
int main()
{
    queue que(7);
    que.enqueue(1);
    que.enqueue(2);
    que.enqueue(3);
    que.enqueue(4);
    que.enqueue(5);
    que.enqueue(6);
    que.enqueue(11);
    que.dequeue();
    que.dequeue();
    que.dequeue();
    que.enqueue(11);
    que.enqueue(12);
    que.enqueue(13);
    que.enqueue(11);
    que.display();
}
