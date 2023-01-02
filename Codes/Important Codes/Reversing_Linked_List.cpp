#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class linkedlist
{
public:
    node *first=NULL;
    linkedlist(int *arr, int n);
    void display();
    void reverse(node *p,node *q);
};
linkedlist::linkedlist(int *arr, int n)
{
    first=new node;
    first->data=arr[0];
    first->next=NULL;
    node *q=first;
    for(int i=1;i<n;i++)
    {
        node *temp=new node;
        temp->data=arr[i];
        temp->next=NULL;
        q->next=temp;
        q=temp;
    }
}
void linkedlist::display()
{
    node *p=first;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
void linkedlist::reverse(node *p, node *q)
{
    if(p!=NULL)
    {
        reverse(p->next,p);
        p->next=q;
    }
    else
    {
        first=q;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]); // finds size of array without asking the user
    linkedlist l(arr,n);
    l.display();
    l.reverse(l.first,NULL);
    cout<<endl;
    l.display();
    return 0;
}