#include <iostream> 
#include<cstring>
using namespace std;
void display(int *A, int m, int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j)
             cout<<A[(i*(i-1))/2+j-1]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    return;
}
int main()
{
    int *A,n,m;
    cout<<"Enter dimension: ";
    cin>>n;
    m=(n*(n+1))/2;
    A=new int[m];
    cout<<"Enter elements: ";
    for(int i=0;i<m;i++)
     cin>>A[i];
    display(A,m,n);
    return 0;
}