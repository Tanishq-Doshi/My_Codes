#include <iostream> 
#include<cstring>
using namespace std;
class sparse
{
    private:
    int *i; // row
    int *j; // column
    int *k; // element
    public:
    void read();
    void display();
};
void sparse::read()
{
    int no;
    cout<<"Enter number of non-zero elements: ";
    cin>>no;
    i=new int[no+1];
    j=new int[no+1];
    k=new int[no+1];
    k[0]=no;
    cout<<"Enter dimensions: ";
    cin>>i[0]>>j[0];
    cout<<"Enter row number, column number and the non-zero element: ";
    for(int a=1;a<=k[0];a++)
     cin>>i[a]>>j[a]>>k[a];
}
void sparse::display()
{
    int count=1;
    for(int a=1;a<=i[0];a++)
    {
        for(int b=1;b<=j[0];b++)
        {
            if(i[count]==a && j[count]==b)
            {
                cout<<k[count]<<" ";
                count++;
            }
            else cout<<"0 ";
        }
        cout<<endl;
    }
}
int main()
{
    sparse s;
    s.read();
    s.display();
    return 0;
}