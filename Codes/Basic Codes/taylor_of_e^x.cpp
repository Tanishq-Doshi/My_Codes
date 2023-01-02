#include <iostream> // taylor series
using namespace std;
float pow(float x2, float n2)
{
    if(n2>0)
    {
        return pow(x2,n2-1)*x2;
    }
    return 1;
}
float fac(float n3)
{
    if(n3>0)
    {
        return fac(n3-1)*n3;
    }
    return 1;
}
float tay(float x1, float n1)
{
    if(n1>0)
    {
        return tay(x1,n1-1)+(pow(x1,n1)/fac(n1));
    }
    return 1;
}
int main()
{
    cout<<"Enter highest degree required: ";
    float x,n;
    scanf("%f",&n);
    cout<<"Enter value of x: ";
    scanf("%f",&x);
    cout<<"Required value is: "<<tay(x,n);
    return 0;
}