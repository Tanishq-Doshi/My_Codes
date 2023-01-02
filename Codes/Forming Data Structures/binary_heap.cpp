#include<bits/stdc++.h>
using namespace std;
void swap(int *x, int *y)
{
  int temp=*x;
  *x=*y;
  *y=temp;
}
void Heapify(int *arr, int N)
{
  for(int i=N;i>0;i--)
  {
    if(2*i>N)
     continue;
    if(arr[i]<arr[2*i] && arr[2*i]<arr[(2*i)+1])
    {
     swap(&arr[i],&arr[(2*i)+1]);
     i=(2*i)+2;
    }
    else if(arr[i]<arr[2*i] && arr[2*i]>arr[(2*i)+1])
    {
     swap(&arr[i],&arr[2*i]);
     i=(2*i)+2;
    }
  }
}
int main()
{
  int arr[]={-1,5,10,30,20,35,40,15};
  int N=sizeof(arr)/sizeof(arr[0]);
  Heapify(arr,N-1);
  for(int i=1;i<N;i++)
   cout<<arr[i]<<" ";
  return 0;
}
