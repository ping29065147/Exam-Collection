static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n)
    {
        vector<int> ret;
        
        for (int i = 0; i < n; ++i)
        {
            ret.push_back(nums[i]);
            ret.push_back(nums[i + n]);
        }
        
        return ret;
    }
};