static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int arrayPairSum(vector<int>& nums)
    {
        int ret = 0;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2) ret += nums[i];
        
        return ret;
    }
};