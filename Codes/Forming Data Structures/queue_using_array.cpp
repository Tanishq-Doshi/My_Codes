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
    void push(int x);
    int pop();
    void display();  
};
queue::queue(int size1)
{
    size=size1;
    Q=new int[size];
    front=rear=-1;
}
void queue::push(int x)
{
    if(rear==size-1) // queue is full
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    rear++;
    Q[rear]=x;
}
int queue::pop()
{
    int x=-1;
    if(front==rear) // queue is empty
    {
        cout<<"Queue is empty"<<endl;
        return x;
    }
    front++;
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
    for(int i=front+1;i<=rear;i++)
     cout<<Q[i]<<" ";
}
int main()
{
    queue que(7);
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);
    que.push(6);
    que.push(7);
    que.push(8);
    que.push(9);
    que.pop();
    que.display();
}
