static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minimumCost(vector<int>& cost)
    {
        int cnt = 0;
        
        sort(cost.begin(), cost.end(), greater<int>());
        for (int i = 0; i < cost.size(); ++i)
        {
            if (i % 3 == 2) continue;
            cnt += cost[i];
        }
        
        return cnt;
    }
};