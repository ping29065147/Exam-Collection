static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxProductDifference(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());     
        return (nums[nums.size() - 2] * nums.back()) - (nums[0] * nums[1]);
    }
};