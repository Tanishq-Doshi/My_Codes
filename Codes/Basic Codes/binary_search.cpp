#include<iostream>
using namespace std;
int binsearch(int *a,int x,int n)
{
    int l=0;
    int h=n-1;
    int mid;
    while(h>=l)
    {
        mid=(l+h)/2;
        if(x>a[mid])
         l=mid+1;
        else if(x<a[mid])
         h=mid-1;
        else return mid+1;
    }
    return -1;
}
int main()
{
    int a[]={1,2,3,5,7};
    int x=45;
    int n=sizeof(a)/sizeof(a[0]);
    if(binsearch(a,x,n)==-1)
     cout<<"Not found";
    else cout<<"Element found at index "<<binsearch(a,x,n);
}