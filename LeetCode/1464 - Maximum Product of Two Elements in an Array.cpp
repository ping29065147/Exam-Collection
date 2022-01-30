static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        return (nums[0] - 1) * (nums[1] - 1);
    }
};