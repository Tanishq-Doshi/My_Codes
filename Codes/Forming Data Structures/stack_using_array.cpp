#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Stack
{
private:
    int size;
    int top; // index
    int *s; // array
public:
    Stack(int size1);
    void push(int x);
    int pop();
    void display();
    int peek(int pos);
};
Stack::Stack(int size1)
{
    size=size1;
    s=new int(size);
    top=-1;
}
void Stack::push(int x)
{
    if(top==size-1) // stack full if top=size-1
     cout<<"Stack Overflow"<<endl;
    else
    {
        top++;
        s[top]=x;
    }
    return;
}
int Stack::pop()
{
    int x=-1;
    if(top==-1) // stack empty if top=-1
    {
    cout<<"Stack Underflow"<<endl;
    return x;
    }
    else
    {
        x=s[top];
        top--;
    }
    return x;
}
int Stack::peek(int pos)
{
    if(top-pos+1<0)
    {
        cout<<"Invalid index"<<endl;
        return -1;
    }
    else
    {
        return s[top-pos+1];
    }
}
void Stack::display()
{
    for(int i=top;i>=0;i--)
     cout<<s[i]<<endl;
    cout<<endl;
}
int main()
{
    Stack st(5);
    st.push(4);
    st.push(5);
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    st.display();
}