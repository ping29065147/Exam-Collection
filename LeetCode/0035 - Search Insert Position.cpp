static auto fast_io = []
{
    ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {        
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};