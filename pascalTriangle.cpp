#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
    void printPascalTriangle(int rows)
    {
        for(int i=1;i<=rows;i++)
        {
            int num=i-1,den=1;
            int res=1;
            for(int j=1;j<=rows;j++)
            {
                if(j>=rows-i+1 and j<=rows+i-1)
                {
                    cout<<res<<" ";
                    res=(res*num)/den;
                    num--;
                    den++;
                }
                else    
                    cout<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Solution obj;
    int input=0;
    cout<<"Enter number of Rows..\n";
    cin>>input;
    obj.printPascalTriangle(input);
    return 0;
}