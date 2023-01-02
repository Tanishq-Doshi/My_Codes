#include<bits/stdc++.h>
#include<queue>
using namespace std;
class Node
{
public:
  int data;
  Node *leftchild;
  Node *rightchild;
  int level;
};
int nodelevel(Node *p)
{
  int leftlevel,rightlevel;
  leftlevel= (p!=NULL && p->leftchild!=NULL ? p->leftchild->level : 0);
  rightlevel = (p!=NULL && p->rightchild!=NULL ? p->rightchild->level : 0);
  return leftlevel>rightlevel ? leftlevel+1 : rightlevel+1;
}
int balancefactor(Node *p)
{
  int leftlevel,rightlevel;
  leftlevel= (p!=NULL && p->leftchild!=NULL ? p->leftchild->level : 0);
  rightlevel = (p!=NULL && p->rightchild!=NULL ? p->rightchild->level : 0);
  return leftlevel-rightlevel;
}
Node *LLrotation(Node *p)
{
  Node *pl=p->leftchild;
  Node *plr=pl->rightchild;
  pl->rightchild=p;
  p->leftchild=plr;
  p->level=nodelevel(p);
  pl->level=nodelevel(pl);
  return pl;
}
Node *LRrotation(Node *p)
{
 Node *pl=p->leftchild;
 Node *plr=pl->rightchild;
 pl->rightchild=plr->leftchild;
 p->leftchild=plr->rightchild;
 plr->leftchild=pl;
 plr->rightchild=p;
 pl->level=nodelevel(pl);
 p->level=nodelevel(p);
 plr->level=nodelevel(plr);
 return plr;
}
Node *avl_insert(Node *p, int key)
{
  Node *t;
  if(p==NULL)
  {
    t=new Node;
    t->leftchild=t->rightchild=NULL;
    t->data=key;
    t->level=1;
    return t;
  }
  if(key>p->data)
   p->rightchild=avl_insert(p->rightchild,key);
  else if(key<p->data)
   p->leftchild=avl_insert(p->leftchild,key);
  p->level=nodelevel(p);
  if(balancefactor(p)==2 && balancefactor(p->leftchild)==1)
   return LLrotation(p);
  else if(balancefactor(p)==2 && balancefactor(p->leftchild)==-1)
   return LRrotation(p);
  // else if(balancefactor(p)==-2 && balancefactor(p->leftchild)==-1)
  //  return RRrotation(p);
  // else if(balancefactor(p)==-2 && balancefactor(p->leftchild)==1)
  //  return RLrotation(p);
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
  Node *root=avl_insert(root,30);
  avl_insert(root,20);
  avl_insert(root,10);
  levelorder(root);
}