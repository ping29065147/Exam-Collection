static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff)
    {
        int ans = 0, n = nums.size();

        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = i + 1; j < n - 1; ++j)
            {
                if (nums[j] - nums[i] < diff) continue;
                else if (nums[j] - nums[i] > diff) break;

                for (int k = j + 1; k < n; ++k)
                {
                    if (nums[k] - nums[j] == diff) ++ans;
                    else if (nums[k] - nums[j] > diff) break;
                }
            }
        }

        return ans;
    }
};