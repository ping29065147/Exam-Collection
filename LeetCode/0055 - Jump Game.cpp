static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size();
        int cur = 0;
        
        for (int i = 0; i < n; ++i)
        {
            if (i > cur || cur >= n - 1) break;
            cur = max(cur, i + nums[i]);
        }
        
        return cur >= n - 1;
    }
};