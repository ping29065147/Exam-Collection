static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> buildArray(vector<int>& nums)
    {
        vector<int> V(nums.size());       
        for (int i = 0; i < nums.size(); ++i) V[i] = nums[nums[i]];
        return V;
    }
};