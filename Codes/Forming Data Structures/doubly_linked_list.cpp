#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
};
class doublylinkedlist
{
public:
    node *first=NULL;
    doublylinkedlist(int *arr, int n);
    void display();
    void reversedisplay();
};
doublylinkedlist::doublylinkedlist(int *arr, int n)
{
    first=new node;
    first->data=arr[0];
    first->next=first->prev=NULL;
    node *q=first;
    for(int i=1;i<n;i++)
    {
        node *temp=new node;
        temp->data=arr[i];
        temp->next=NULL;
        temp->prev=q;
        q->next=temp;
        q=temp;
    }
}
void doublylinkedlist::display()
{
    node *p=first;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
void doublylinkedlist::reversedisplay()
{
    node *p=first;
    while(p->next!=NULL)
     p=p->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->prev;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 7, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]); // finds size of array without asking the user
    doublylinkedlist l(arr,n);
    l.display();
    return 0;
}