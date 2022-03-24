static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int subsetXORSum(vector<int>& nums)
    {
        return dfs(nums, 0, 0);
    }
    
    int dfs(vector<int>& nums, int i, int x)
    {
        if (i == nums.size()) return x;
        int a = dfs(nums, i + 1, x);
        int b = dfs(nums, i + 1, x ^ nums[i]);
        return a + b;
    }
};