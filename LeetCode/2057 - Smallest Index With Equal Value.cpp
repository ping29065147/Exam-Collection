static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int smallestEqual(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); ++i)
            if (i % 10 == nums[i])
                return i;
        return -1;
    }
};