#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Node
{
public:
  int data;
  Node *leftchild;
  Node *rightchild;
};
class Tree
{
private:
  queue<Node*> Q;
  Node *p,*temp;
  int x;
public:
  Node *root;
  Tree();
  void preorder(Node *t);
  void inorder(Node *t);
  void postorder(Node *t);
  void levelorder();
  int countNodes(Node *n);
  int level(Node *n);
};
Tree::Tree()
{
  cout<<"Enter root value: ";
  cin>>x;
  root=new Node;
  root->data=x;
  root->leftchild=root->rightchild=NULL;
  Q.push(root);
  while(Q.size()!=0)
  {
    p=Q.front();
    Q.pop();
    cout<<"Enter left value of "<<p->data<<" : ";
    cin>>x;
    if(x!=-1)
    {
      temp=new Node;
      temp->leftchild=temp->rightchild=NULL;
      temp->data=x;
      p->leftchild=temp;
      Q.push(temp);
    }
    cout<<"Enter right value of "<<p->data<<" : ";
    cin>>x;
    if(x!=-1)
    {
      temp=new Node;
      temp->leftchild=temp->rightchild=NULL;
      temp->data=x;
      p->rightchild=temp;
      Q.push(temp);
    }
  }
}
void Tree::preorder(Node *t)
{
  if(t!=NULL)
  {
  cout<<t->data<<" ";
  preorder(t->leftchild);
  preorder(t->rightchild);
  }
}
void Tree::inorder(Node *t)
{
  if(t!=NULL)
  {
  inorder(t->leftchild);
  cout<<t->data<<" ";
  inorder(t->rightchild);
  }
}
void Tree::postorder(Node *t)
{
  if(t!=NULL)
  {
  postorder(t->leftchild);
  postorder(t->rightchild);
  cout<<t->data<<" ";
  }
}
void Tree::levelorder()
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
}
int Tree::countNodes(Node *n)
{
  if(n==NULL)
   return 0;
  else
   return countNodes(n->leftchild)+countNodes(n->rightchild)+1;
}
int Tree::level(Node *n)
{
  if(n==NULL)
   return 0;
  else
  {
    int x=level(n->leftchild);
    int y=level(n->rightchild);
    if(x>y)
     return x+1;
    else return y+1;
  }
}
void avg_of_levels(Node *root)
{
  queue <Node*> que;
  que.push(root);
  Node *p=NULL;
  while(que.size()!=0)
  {
    queue <Node*> quetemp;
    int sum=0,count=0;
    while(que.size()!=0)
    {
      p=que.front();
      que.pop();
      sum=sum+p->data;
      count++;
      if(p->leftchild!=NULL)
       quetemp.push(p->leftchild);
      if(p->rightchild!=NULL)
       quetemp.push(p->rightchild);
    }
    cout<<(sum*1.0)/count<<" ";
    que=quetemp;
  }
}
int main()
{
  Tree t;
  avg_of_levels(t.root);
  return 0;
}
