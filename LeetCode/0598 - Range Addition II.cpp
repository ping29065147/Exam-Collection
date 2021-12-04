static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops)
    {
        for (auto& op : ops)
        {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        
        return m * n;
    }
};