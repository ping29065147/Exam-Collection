static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        if (!nums.size()) return 0;
        
        int i = -1;
        for (int j = 0; j < nums.size(); ++j)
            if (nums[j] != val)
                nums[++i] = nums[j];
        
        return i + 1;
    }
};