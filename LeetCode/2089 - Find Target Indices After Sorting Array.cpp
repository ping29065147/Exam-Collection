static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target)
    {
        vector<int> V;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == target)
                V.push_back(i);
        
        return V;
    }
};