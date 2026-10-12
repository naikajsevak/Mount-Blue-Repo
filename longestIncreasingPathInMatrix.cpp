#include <bits/stdc++.h>
using namespace std;

class Solution
{

    vector<int> dir1 = {1, -1, 0, 0};
    vector<int> dir2 = {0, 0, 1, -1};

    int solve(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        int res = 0;
        int currentCellValue = mat[i][j];
        for (int l = 0; l < 4; l++)
        {
            int row = i + dir1[l];
            int col = j + dir2[l];
            if (row >= 0 and row < mat.size() and col >= 0 and col < mat[0].size() and currentCellValue < mat[row][col])
                res = max(res, 1 + solve(mat, row, col, dp));
        }
        return dp[i][j] = res;
    }
    int tab(vector<vector<int>> &mat,int i,int j)
    {
        
    }
    void print(vector<vector<int>> &dp)
    {
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[i].size(); j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
    public:
    int findLongestIncPathInGrid(vector<vector<int>> &mat)
    {
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), -1));
        int ans = 0;

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                print(dp);
                ans = max(ans, solve(mat, i, j, dp));
            }
        }
        return ans+1;
    }
};

int main()
{
    vector<vector<int>> mat={{1,2},{4,3}};
    Solution obj;
    cout<<obj.findLongestIncPathInGrid(mat);
    return 0;
}