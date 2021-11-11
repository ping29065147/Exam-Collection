static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> ret;
        
        for (int i = 0, j; i < nums.size(); i += j)
        {
            j = 1;
            while(i + j < nums.size() && (long)nums[i + j] - nums[i] == j) ++j;
            ret.push_back(j == 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
        }
        
        return ret;
    }
};