static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maximumProduct(vector<int>& nums)
    {
        int S = nums.size();
        sort(nums.begin(), nums.end());
        return max(nums[S - 1] * nums[S - 2] * nums[S - 3], nums[0] * nums[1] * nums[S - 1]);
    }
};