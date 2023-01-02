#include <bits/stdc++.h>
using namespace std;
void BFS(int G[][7], int start, int n)
{
  queue<int> que;
  vector<int> arr(n,0);
  cout<<start<<" ";
  que.push(start);
  arr[start]=1;
  while(que.size()!=0)
  {
    int k=que.front();
    arr[k]=1;
    que.pop();
    for(int i=1;i<=n;i++)
    {
      if(G[k][i]==1 && arr[i]==0)
      {
        cout<<i<<" ";
        arr[i]=1;
        que.push(i);
      }
    }
  }
}
void DFS(int G[][7], int start, int n)
{
  static vector<int> arr(n,0);
  arr[start]=1;
  if(arr[start]==1)
   cout<<start<<" ";
  for(int i=1;i<=n;i++)
  {
    if(G[start][i]==1 && arr[i]==0)
    {
      arr[i]=1;
      DFS(G,i,n);
    }
  }
}
int main()
{
  int G[7][7]={{0,0,0,0,0,0,0},    //                 1
               {0,0,1,1,0,0,0},    //                /  \'
               {0,1,0,0,1,0,0},    //               2    3
               {0,1,0,0,1,0,0},    //                \  /
               {0,0,1,1,0,1,1},    //                  4
               {0,0,0,0,1,0,0},    //                 / \'
               {0,0,0,0,1,0,0}};   //                5   6
 BFS(G,4,7);
 cout<<endl;
 DFS(G,4,7);
 return 0;
}