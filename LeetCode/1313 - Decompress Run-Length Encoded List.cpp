static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums)
    {
        vector<int> ret;
        
        for (int i = 0; i < nums.size(); i += 2)
            for (int j = 0; j < nums[i]; ++j)
                ret.push_back(nums[i + 1]);
        
        return ret;
    }
};