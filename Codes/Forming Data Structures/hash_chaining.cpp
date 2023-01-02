#include <bits/stdc++.h>
using namespace std;
class node
{
public:
  int data;
  node *next;
};
void hash_insert(int key, vector<node*> &hash_table)
{
  int index=key%10;
  node *p=hash_table[index],*q=NULL;
  node *temp=new node;
  temp->data=key;
  temp->next=NULL;
  if(hash_table[index]==NULL)
   hash_table[index]=temp;
  else
  {
    while(p->data<key && p!=NULL)
    {
      q=p;
      p=p->next;
    }
    if(p==hash_table[index])
    {
      temp->next=p;
      hash_table[index]=temp;
    }
    else
    {
    q->next=temp;
    temp->next=p;
    }
  }
}
vector<node*> hash_chaining(vector<int> &vec)
{
  vector<node*> hash_table(10,NULL);
  for(int i=0;i<vec.size();i++)
   hash_insert(vec[i],hash_table);
  return hash_table;
}
int search(vector<node*> &hash_table, int key)
{
  int index=key%10;
  node *p=hash_table[index];
  while(p!=NULL)
  {
    if(p->data==key)
     return 1;
    else p=p->next;
  }
  return 0;
}
int main()
{
  vector<int> vec={16,12,25,39,6,122,5,68,75};
  vector<node*> hash_table = hash_chaining(vec);
  search(hash_table,22) ? cout<<"Found" : cout<<"Not Found";
  // Code not working but basic code structure can be used for reference
}