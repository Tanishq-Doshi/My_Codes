#include <iostream> 
#include<cstring>
#include<math.h>
using namespace std;
class poly
{
    public:
    int *coeff; 
    int *exp; 
    int n; 
    void read();
    float value(int x);
    void sum(poly p1, poly p2, poly p3);
};
void sum(poly p1, poly p2, poly *p3)
{
    int i=0,j=0,k=0;
    p3->n=p1.n+p2.n;
    p3->coeff=new int[p3->n];
    p3->exp=new int[p3->n];
    while(i<p1.n && j<p2.n)
    {
        if(p1.exp[i]==p2.exp[j])
        {
            p3->exp[k]=p1.exp[i];
            p3->coeff[k]=p1.coeff[i]+p2.coeff[j];
            i++;
            j++;
            k++;
        }
        else if(p1.exp[i]>p2.exp[j])
        {
            p3->exp[k]=p1.exp[i];
            p3->coeff[k]=p1.coeff[i];
            i++;
            k++;
        }
        else
        {
            p3->exp[k]=p2.exp[j];
            p3->coeff[k]=p2.coeff[j];
            j++;
            k++;  
        }
    }
    p3->n=k;
}
void poly::read()
{
    cout<<"Enter number of non-zero elements: ";
    cin>>n;
    coeff=new int[n];
    exp=new int[n];
    cout<<"Enter coefficient and exponent of non-zero element: ";
    for(int a=0;a<n;a++)
     cin>>coeff[a]>>exp[a];
}
float poly::value(int x)
{
    float sum=0;
    for(int a=0;a<n;a++)
    {
        sum=sum+coeff[a]*pow(x,exp[a]);
    }
    return sum;
}
int main()
{
    poly p1,p2,p3;
    int x;
    p1.read();
    p2.read();
    cout<<"Enter value of x: ";
    cin>>x;
    cout<<p1.value(x)+p2.value(x)<<endl;
    sum(p1,p2,&p3);
    cout<<p3.value(x);
    return 0;
}