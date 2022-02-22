static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts)
    {
        int cnt = 0;        
        for (auto& v : accounts) cnt = max(cnt, accumulate(v.begin(), v.end(), 0));       
        return cnt;
    }
};