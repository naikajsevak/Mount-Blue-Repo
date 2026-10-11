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
            int col = j + dir2[i];
            if (row >= 0 and row < mat.size() and col >= 0 and col < mat[0].size() and currentCellValue < mat[row][col])
                res = max(res, 1 + solve(mat, row, col, dp));
        }
        return dp[i][j] = res;
    }
    /*int tab(vector<vector<int>> &mat,int i,int j)
    {
        
    }*/
    public:
    int findMaxIncPathInGrid(vector<vector<int>> &mat)
    {
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), -1));
        int ans = 0;

        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[i].size(); j++)
                ans = max(ans, solve(mat, i, j, dp));
        return ans;
    }
};

int main()
{
    vector<vector<int>> mat={{1,2},{4,3}};
    Solution obj;
    cout<<obj.findMaxIncPathInGrid(mat);
    return 0;
}