static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findLHS(vector<int>& nums)
    {
        int ret = 0;
        unordered_map<int, int> M;
        
        for (auto& i : nums) ++M[i];
        for (auto& [i, j] : M) if (M.count(i + 1)) ret = max(ret, j + M[i + 1]);
        
        return ret;
    }
};