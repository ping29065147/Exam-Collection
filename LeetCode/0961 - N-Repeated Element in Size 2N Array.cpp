static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int repeatedNTimes(vector<int>& nums)
    {
        unordered_map<int, int> M;
        
        for (auto& i : nums) ++M[i];
        for (auto& [i, j] : M) if (j == nums.size() / 2) return i;
        return 0;
    }
};