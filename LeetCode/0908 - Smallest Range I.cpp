static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k)
    {
        auto Max = max_element(nums.begin(), nums.end());
        auto Min = min_element(nums.begin(), nums.end());
        
        return *Max - *Min <= k * 2 ? 0 : *Max - *Min - k * 2; 
    }
};