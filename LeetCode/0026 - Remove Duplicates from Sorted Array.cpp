static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() == 0) return 0;
        
        int i = 0;
        for (int j = 0; j < nums.size(); ++j)
           if (nums[i] != nums[j])
               nums[++i] = nums[j];
        
        return i + 1;
    }
};