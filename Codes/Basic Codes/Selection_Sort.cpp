#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y)
{
  int temp=*x;
  *x=*y;
  *y=temp;
}
void selectionsort(int *arr,int n)
{
  for(int i=0;i<n-1;i++)
  {
    int j=i+1,k=i;
    for(;j<n;j++)
    {
      if(arr[j]<arr[k])
       k=j;
    }
    swap(&arr[i],&arr[k]);
  }
}
int main()
{
  int arr[] = {8,5,9,7,3,2,7,7,1};
  int n = sizeof(arr) / sizeof(arr[0]); // finds size of array without asking the user
  selectionsort(arr,n);
  for(int i=0;i<n;i++)
   cout<<arr[i]<<" ";
  return 0;
}