static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right)
    {
        vector<int> V(52, 0);
        
        for (auto& i : ranges) ++V[i[0]], --V[i[1] + 1];
        for (int i = 1; i < 52; ++i) V[i] += V[i - 1];
        
        for (int i = left; i <= right; ++i) if (!V[i]) return false;
        return true;
    }
};