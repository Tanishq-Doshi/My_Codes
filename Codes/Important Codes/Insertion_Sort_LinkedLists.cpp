#include<bits/stdc++.h>
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
void display(node *first)
{
    node *p=first;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void sortedinsert(node **root,int data)
{
  node *fast=*root;
  node *slow=NULL;
  while(fast->data<=data && fast!=NULL)
  {
    slow=fast;
    fast=fast->next;
  }
  if(slow==NULL)
  {
    node *newww=new node;
    newww->data=data;
    newww->next=fast;
    *root=newww;
  }
  else
  {
  node *neww=new node;
  neww->data=data;
  neww->next=fast;
  slow->next=neww;
  }
}
node *insertionsort(node *root, int n)
{
  node *org=root;
  node *neww=new node;
  neww->data=root->data;
  neww->next=NULL;
  org=org->next;
  while(org!=NULL)
  {
    sortedinsert(&neww,org->data);
    org=org->next;
  }
  return neww;
}
int main()
{
  int arr[] = {8,5,7,3,2,7,7,7};
  int n = sizeof(arr) / sizeof(arr[0]); // finds size of array without asking the user
  linkedlist l(arr,n);
  display(l.first);
  node *root=insertionsort(l.first,n);
  display(root);
  return 0;
}