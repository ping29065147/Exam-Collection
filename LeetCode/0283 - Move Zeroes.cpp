static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int ptr = 0;
        
        for (int i = 0; i <nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                if (ptr != i)
                {
                    nums[ptr] = nums[i];
                    nums[i] = 0;
                }
                ++ptr;
            }
        }
    }
};