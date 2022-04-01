static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findMiddleIndex(vector<int>& nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int cur = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (cur == sum - cur - nums[i]) return i;
            cur += nums[i];
        }
        
        return -1;
    }
};