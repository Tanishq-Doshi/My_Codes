#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class Stack
{
private:
    node *top;
public:
    Stack();
    void push(int x);
    int pop();
    void display();
    int peek(int pos);
};
Stack::Stack()
{
    top=NULL;
}
void Stack::push(int x)
{
    node *t=new node;
    if(t==NULL) // stack full if heap has no space
     cout<<"Stack Overflow"<<endl;
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
    return;
}
int Stack::pop()
{
    int x=-1;
    if(top==NULL) // stack empty if top=NULL
    {
    cout<<"Stack Underflow"<<endl;
    return x;
    }
    else
    {
        node *t=top;
        x=top->data;
        top=top->next;
        delete []t;
    }
    return x;
}
int Stack::peek(int pos)
{
    node *p=top;
    for(int i=0;i<pos-1 && p!=NULL;i++)
     p=p->next;
    if(p==NULL)
    {
    cout<<"Invalid index"<<endl;
    return -1;
    }
    else
    {
        return p->data;
    }
}
void Stack::display()
{
    node *p=top;
    for(int i=0;p!=NULL;i--)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    Stack st;
    st.push(4);
    st.push(5);
    st.push(12);
    st.pop();
    cout<<st.peek(3)<<endl<<endl;
    st.display();
}