#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char a[30];
    gets(a);
    long int H=0,x=0;  // long int = 4 bytes = 32 bits, sufficient array space for lower space alphabets (26)
    for(int i=0;a[i]!='\0';i++)
    {
        x=1;
        x=x<<a[i]-97; // 97 because ascii value of a is 97 which is first bit in long int used
        if(x&H>0) // If 0, then not yet repeated
        {
            cout<<char(a[i])<<" is repeated"<<endl;
        }
        else H=x|H; // assigning H=1 for that character
    }
}
