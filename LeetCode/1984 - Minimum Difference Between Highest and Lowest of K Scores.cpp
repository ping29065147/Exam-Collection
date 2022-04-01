static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int ret = INT_MAX;
        
        for (int i = k - 1; i < nums.size(); ++i)
            ret = min(ret, nums[i] - nums[i - k + 1]);
        
        return ret;
    }
};