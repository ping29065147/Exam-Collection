static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        int ans = 0, x = 0;
        sort(nums.begin(), nums.end());

        for (auto& i : nums)
        {
            if (i > x) x = i, ++ans;
        }

        return ans;
    }
};