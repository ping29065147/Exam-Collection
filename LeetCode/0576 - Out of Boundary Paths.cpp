static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        
        for (int k = 1; k <= maxMove; ++k)
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                {
                    long long v1 = (i == 0) ? 1 : dp[k - 1][i - 1][j];
                    long long v2 = (i == m - 1) ? 1 : dp[k - 1][i + 1][j];
                    long long v3 = (j == 0) ? 1 : dp[k - 1][i][j - 1];
                    long long v4 = (j == n - 1) ? 1 : dp[k - 1][i][j + 1];
                    
                    dp[k][i][j] = (v1 + v2 + v3 + v4) % 1000000007;
                }
        
        return dp[maxMove][startRow][startColumn];
    }
};