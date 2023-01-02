#include <iostream> 
#include<cstring>
using namespace std;
void swap(char *a, char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
    return;
}
void perm(char *s, int k) 
{
   int n=strlen(s);
   if(k>=n)
   {
     puts(s);
     return;
   }
   else
   {
    for(int i=k;i<n;i++)
    {
        swap(&s[i],&s[k]);
        perm(s,k+1);
        swap(&s[i],&s[k]);
    }
   }
   return;
}
int main()
{
    cout<<"Put string: ";
    char s[10];
    gets(s);
    perm(s,0);
}