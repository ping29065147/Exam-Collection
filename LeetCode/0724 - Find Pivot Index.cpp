static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int pivotIndex(vector<int>& nums)
    {
        int right = 0, left = 0;
        
        for (auto& i : nums) right += i;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (left == right - nums[i] - left) return i;
            left += nums[i];
        }
        
        return -1;
    }
};