static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        double sum = accumulate(nums.begin(), nums.begin() + k, 0);
        double ret = sum;
        
        for (int i = k; i < nums.size(); ++i)
        {
            sum += nums[i] - nums[i - k];
            ret = max(ret, sum);
        }
        
        return ret / k;
    }
};