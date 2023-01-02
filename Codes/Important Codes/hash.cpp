#include <iostream>
using namespace std;
void hashh(int n, int *a, int max)
{
    int *h;
    h=new int[max+1];
    for(int i=0;i<max+1;i++)
     h[i]=0;
    // code
    delete []h;
    return;
}
int main()
{
    int n, *a, max;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter all elements: ";
    a=new int[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    cout<<"Enter max element: ";
    cin>>max;
    hashh(n,a,max);
    return 0;
}