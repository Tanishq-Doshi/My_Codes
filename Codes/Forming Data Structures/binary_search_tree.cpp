#include<bits/stdc++.h>
#include<queue>
using namespace std;
class Node
{
public:
  int data;
  Node *leftchild;
  Node *rightchild;
};
Node *binarysearch(Node *p, int x)
{
  Node *t=p;
  while(t!=NULL)
  {
    if(x==t->data)
     return t;
    else if(x>t->data)
     t=t->rightchild;
    else t=t->leftchild;
  }
  return NULL;
}
Node *binaryinsert(Node *p, int key)
{
  Node *t;
  if(p==NULL)
  {
    t=new Node;
    t->leftchild=t->rightchild=NULL;
    t->data=key;
    return t;
  }
  if(key>p->data)
   p->rightchild=binaryinsert(p->rightchild,key);
  else if(key<p->data)
   p->leftchild=binaryinsert(p->leftchild,key);
  return p;
}
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
int main()
{
  Node *root=NULL;
  root=binaryinsert(root,30);
  binaryinsert(root,15);
  binaryinsert(root,50);
  binaryinsert(root,10);
  binaryinsert(root,20);
  binaryinsert(root,40);
  binaryinsert(root,60);
  binaryinsert(root,15);
  levelorder(root);
  binarysearch(root,20)==NULL ? cout<<"Element not found" : cout<<"Element found";
  return 0;
}
