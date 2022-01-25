static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index)
    {
        vector<int> ret; 
        for (int i = 0; i < index.size(); ++i) ret.insert(ret.begin() + index[i], nums[i]);
        return ret;
    }
};