static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums)
    {
        int n = nums.size();
        bool del = false;
        
        for (int i = 1; i < n; ++i)
        {
            if (nums[i - 1] >= nums[i])
            {
                if (!del)
                {
                    if (i == 1 || nums[i] > nums[i - 2] || i == n - 1 || nums[i - 1] < nums[i + 1]) del = true;
                    else return false;
                }
                else return false;
            }
        }
        
        return true;
    }
};