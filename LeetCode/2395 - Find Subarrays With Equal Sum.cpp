static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool findSubarrays(vector<int>& nums)
    {
        unordered_map<int, int> M;

        for (int i = 1; i < nums.size(); ++i) ++M[nums[i] + nums[i - 1]];
        for (auto& [i, j] : M) if (j > 1) return true;

        return false;
    }
};