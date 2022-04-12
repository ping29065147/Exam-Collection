static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original)
    {
        while(find(nums.begin(), nums.end(), original) != nums.end()) original <<= 1;
        return original;
    }
};