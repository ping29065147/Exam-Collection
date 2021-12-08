static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        int Max = 1;
        int sum = 1;
        
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1]) ++sum;
            else sum = 1;
            Max = max(Max, sum);
        }
        
        return Max;
    }
};