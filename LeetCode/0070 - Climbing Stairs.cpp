static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int climbStairs(int n)
    {
        int dp[n + 1];
        
        dp[0] = dp[1] = 1;      
        for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2];
        
        return dp[n];
    }
};