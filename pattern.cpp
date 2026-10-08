#include<bits/stdc++.h>
using namespace std;
bool check(string &s,int i,int j)
{
    while(i<=j)
    {
        if(s[i]!=s[j])
            return false;
        i++;j--;
    }
    return true;
}
int solve(string &s,int i)
{
    if(i>=s.size())
        return 0;

    int ans=INT_MAX;

    for(int j=i;j<s.size();j++)
    {
        if(check(s,i,j))
            ans=min(ans,1+solve(s,j+1));
    }
    return ans;
}
int tab(string &s)
{
    vector<int> dp(s.size()+1,0);
    for(int i=s.size()-1;i>=0;i--)
    {
        int ans=INT_MAX;
        for(int j=i;j<s.size();j++)
        {
             if(check(s,i,j))
                ans=min(ans,1+dp[j+1]);
        }
        dp[i]=ans;
    }
    return dp[0];
}
void printPattern(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==1 or i==n)
                cout<<"*";
            else if(j==1 or j==n or j==i or j==n-i+1)
                cout<<"*";
            else   
                cout<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    /*int n=5;
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
    string s="naikaj";
    cout<<tab(s)-1;*/
    printPattern(5);
    
    return 0;
}