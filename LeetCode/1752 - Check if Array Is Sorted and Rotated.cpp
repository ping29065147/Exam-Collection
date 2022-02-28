static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool check(vector<int>& nums)
    {
        int n = nums.size(), rotate = 0;
        
        for (int i = 0; i < n; ++i)
            if (nums[i] > nums[(i + 1) % n] && ++rotate > 1)
                return false;
        return true;
    }
};