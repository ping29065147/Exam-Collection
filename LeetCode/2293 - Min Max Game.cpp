static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minMaxGame(vector<int>& nums)
    {
        int n = nums.size(), x = 1;

        while(n != 1)
        {
            for (int i = 0, j = -1; i < n; i += 2)
            {
                nums[++j] = x ? min(nums[i], nums[i + 1]) : max(nums[i], nums[i + 1]);
                x ^= 1;
            }
            n /= 2;
        }

        return nums[0];
    }
};