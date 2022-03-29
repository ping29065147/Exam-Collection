static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i) nums.push_back(nums[i]);
        return nums;
    }
};