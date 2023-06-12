static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums)
    {
        int cnt = 0;
        unordered_map<int, int> M;

        for (auto& i : nums) ++M[i];
        for (auto& [i, j] : M) if (j >= 2) cnt += j / 2;

        return {cnt, int(nums.size() - cnt * 2)};
    }
};