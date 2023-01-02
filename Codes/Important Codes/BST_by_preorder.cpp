#include<bits/stdc++.h>
#include<queue>
#include<stack>
using namespace std;
class Node
{
public:
  int data;
  Node *leftchild;
  Node *rightchild;
};
void levelorder(Node *root)
{
  queue<Node*> lvl;
  lvl.push(root);
  cout<<root->data<<" ";
  Node *t=NULL;
  while(lvl.size()!=0)
  {
    t=lvl.front();
    lvl.pop();
    if(t->leftchild!=NULL)
    {
      cout<<t->leftchild->data<<" ";
      lvl.push(t->leftchild);
    }
    if(t->rightchild!=NULL)
    {
      cout<<t->rightchild->data<<" ";
      lvl.push(t->rightchild);
    }
  }
  cout<<endl;
}
Node *bst_preorder(int *arr,int N) // start from right of array for postorder BST formation
{
  stack <Node*> st;
  Node *inf=new Node;
  inf->leftchild=inf->rightchild=NULL;
  inf->data=INT_MAX;
  st.push(inf);
  Node *root=new Node;
  root->leftchild=root->rightchild=NULL;
  root->data=arr[0];
  Node *p=root;
  for(int i=1;i<N;i++)
  {
    if(arr[i]<p->data)
    {
      Node *temp=new Node;
      temp->leftchild=temp->rightchild=NULL;
      temp->data=arr[i];
      p->leftchild=temp;
      st.push(p);
      p=temp;
    }
    else
    {
      if(st.top()->data>arr[i])
      {
        Node *temp=new Node;
        temp->leftchild=temp->rightchild=NULL;
        temp->data=arr[i];
        p->rightchild=temp;
        p=temp;
      }
      else
      {
        p=st.top();
        st.pop();
        i--;
      }
    }
  }
  return root;
}
int main()
{
  int arr[]={30,20,10,15,25,40,50,45};
  int N=sizeof(arr)/sizeof(arr[0]);
  Node *root=bst_preorder(arr,N);
  levelorder(root);
  return 0;
}