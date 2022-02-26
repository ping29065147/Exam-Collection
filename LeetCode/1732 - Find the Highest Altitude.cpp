static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int largestAltitude(vector<int>& gain)
    {
        int m = 0, cur = 0;
        
        for (auto& i : gain)
        {
            cur += i;
            m = max(m, cur);
        }
        
        return m;
    }
};