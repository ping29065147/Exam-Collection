static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countElements(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int l = nums[0], r = nums.back();
        int cnt = 0;
        
        for (int i = 1; i < nums.size() - 1; ++i)
            if (nums[i] > l && nums[i] < r)
                ++cnt;
        
        return cnt;
    }
};