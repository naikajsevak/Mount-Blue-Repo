#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=5;
    int m=n*2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j<=i)
                cout<<n-j+1;
            else if(j>=m-i+1)
                cout<<j-n;
            else 
                cout<<" ";
        }
        cout<<endl;
    }   
}