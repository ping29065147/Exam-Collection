static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int S = cost.size();
        int dp[1001] = {0, 0};
        
        for(int i = 2; i <= S; ++i)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        
        return dp[S];
    }
};