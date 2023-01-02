#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int size;
    int top; // index
    char *s; // array
    Stack(int size1);
    void push(char x);
    char pop();
    void display();
    char peek(int pos);
};
Stack::Stack(int size1)
{
    size=size1;
    s=new char(size);
    top=-1;
}
void Stack::push(char x)
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
char Stack::pop()
{
    char x='-';
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
char Stack::peek(int pos)
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
int paranthesis(char *str)
{
    Stack stk(strlen(str));
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            stk.push(str[i]);
        }
        else if(str[i]==')' || str[i]=='}' || str[i]==']')
        {
            if(stk.top==-1)
             return 0;
            else
            {
                char x=stk.pop();
                if(str[i]-x==1 || str[i]-x==2) {}
                else return 0;
            }
        }
        else{}
    }
    if(stk.top==-1)
     return 1;
    else return 0;
}
int main()
{
    char s[]="f[d{a(f)d}q]8(){}{[]}";
    paranthesis(s)==1 ? cout<<"Right" : cout<<"Wrong";
}