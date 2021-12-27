static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        partition(nums.begin(), nums.end(), [](auto a) { return a % 2 == 0; });
        return nums;
    }
};