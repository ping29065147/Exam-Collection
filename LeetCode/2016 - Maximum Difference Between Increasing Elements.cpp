static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maximumDifference(vector<int>& nums)
    {
        int m = nums[0], ret = -1;
        
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] - m > 0) ret = max(ret, nums[i] - m);
            m = min(m, nums[i]);
        }
        
        return ret;
    }
};