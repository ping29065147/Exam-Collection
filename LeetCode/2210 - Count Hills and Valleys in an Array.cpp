static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countHillValley(vector<int>& nums)
    {
        int cnt = 0;
        
        for (int i = 1; i < nums.size() - 1; ++i)
        {
            if (nums[i - 1] == nums[i] || nums[i + 1] == nums[i]) nums.erase(nums.begin() + i), --i;
            else if ((nums[i - 1] < nums[i] && nums[i + 1] < nums[i]) || (nums[i - 1] > nums[i] && nums[i + 1] > nums[i])) ++cnt;
        }
        
        return cnt;
    }
};