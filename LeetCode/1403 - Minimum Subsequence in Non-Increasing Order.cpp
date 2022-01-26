static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int total = 0, i;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        for(i = 0; i < nums.size(); ++i)
        {
            if (sum < total) break;
            sum -= nums[i];
            total += nums[i];
        }
        
        return vector<int>(nums.begin(), nums.begin() + i);
    }
};