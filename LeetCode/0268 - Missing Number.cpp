static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int ret = 0;  
        for (int i = 0; i < nums.size(); ++i) ret += i + 1 - nums[i];    
        return ret;
    }
};