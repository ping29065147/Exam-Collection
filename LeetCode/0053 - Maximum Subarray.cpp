static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int ret = nums[0];
        int cur = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
        {
            cur = max(nums[i], cur + nums[i]);
            ret = max(ret, cur);
        }
        
        return ret;
    }
};