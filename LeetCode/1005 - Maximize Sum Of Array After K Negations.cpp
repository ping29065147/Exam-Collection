static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        int sum = 0;
        int Min = INT_MAX;
        
        sort(nums.begin(), nums.end());
        
        for (auto& i : nums)
        {
            if (k > 0)
            {
                if (i < 0) i = -i, --k;
                Min = min(Min, i);
            }
            
            sum += i;
        }
        
        return k % 2 ? sum - Min * 2 : sum;
    }
};