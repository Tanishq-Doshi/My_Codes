#include <bits/stdc++.h>
using namespace std;
void insertionsort(int *arr,int n)
{
  for(int i=1;i<n;i++)
  {
    int j=i-1;
    int x=arr[i];
    while(j>-1 && arr[j]>x)
    {
      arr[j+1]=arr[j];
      arr[j]=x;
      j--;
    }
  }
}
int main()
{
  int arr[]={9,7,4,8,3,1,2};
  insertionsort(arr,7);
  for(int i=0;i<7;i++)
   cout<<arr[i]<<" ";
}