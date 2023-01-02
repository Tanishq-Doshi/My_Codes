#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string.h>
using namespace std;
void display(vector<vector <int>> &v)
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}
bool sortcol2(vector<int> &v1, vector<int> &v2)
{
    return v1[1]<v2[1]; // ascending according to 2nd column
}
int main()
{
    vector<vector <int>> v={{1,8},{9,5},{3,6},{5,5},{7,1},{2,2}};
    display(v);
    sort(v.begin(),v.end(),sortcol2);
    reverse(v.begin(),v.end()); // reverse
    display(v);
}