#include <iostream>
#include <math.h>
using namespace std;
void display(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << p[i]<<" ";
    }
}
// void swap(int *x, int *y)
// {
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }
void merge(int *p1,int *p2,int *p3,int m,int n, int o)
{
    int i=0,j=0,k=0;
    while(i<m && j<n)
    {
    if(p1[i]<p2[j])
    {
        p3[k]=p1[i];
        i++;
        k++;
    }
    else
    {
        p3[k]=p2[j];
        j++;
        k++; 
    }
    }
    for(;i<m;i++,k++)
     p3[k]=p1[i];
    for(;j<n;j++,k++)
     p3[k]=p2[j];
    cout<<"Merged array is: ";
    display(p3,o);
}
int main()
{
    int *p1,*p2,*p3,m,n,o;
    cout << "Enter number of elements in array 1: ";
    cin >> m;
    p1 = new int[m];
    cout << "Enter sorted array 1: ";
    for (int i = 0; i < m; i++)
    {
        cin >> p1[i];
    }
    cout << "Enter number of elements in array 2: ";
    cin >> n;
    p2 = new int[n];
    cout << "Enter sorted array 2: ";
    for (int i = 0; i < n; i++)
    {
        cin >> p2[i];
    }
    o=m+n;
    p3 = new int[o];
    merge(p1,p2,p3,m,n,o);
    return 0;
}