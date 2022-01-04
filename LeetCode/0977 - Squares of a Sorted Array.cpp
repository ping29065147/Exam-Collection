static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        for (auto& i : nums) i = i * i;
        sort(nums.begin(), nums.end());
        
        return nums;
    }
};