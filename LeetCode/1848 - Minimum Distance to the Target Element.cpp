static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start)
    {
        int m = INT_MAX;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == target)
            {
                m = min(m, abs(i - start));
            }
        }
        
        return m;
    }
};