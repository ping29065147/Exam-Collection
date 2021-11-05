static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int ret = 0;
        int buy = prices[0];
        
        for (int i = 1; i < prices.size(); ++i)
        {           
            ret = max(ret, prices[i] - buy);
            buy = min(buy, prices[i]);
        }
        
        return ret;
    }
};