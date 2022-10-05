class Solution
{
public:
    // this is for solving
    int solving(int i, int j, int maxMove, int r, int c, vector<vector<vector<int>>> &dp)
    {
        int modu = 1e9 + 7;
        if (i < 0 || j < 0 || i >= r || j >= c)
        {
            return true;
        }
        if (maxMove == 0)
        {
            return 0;
        }
        if (dp[i][j][maxMove] != -1)
        {
            return dp[i][j][maxMove];
        }

        int res = 0;
        res += solver(i + 1, j, maxMove - 1, r, c, dp) % modu;
        res += solver(i, j + 1, maxMove - 1, r, c, dp) % modu;
        res += solver(i - 1, j, maxMove - 1, r, c, dp) % modu;
        res += solver(i, j - 1, maxMove - 1, r, c, dp) % modu;
        return dp[i][j][maxMove] = res % modu;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return solver(startRow, startColumn, maxMove, m, n, dp);
    }
};
