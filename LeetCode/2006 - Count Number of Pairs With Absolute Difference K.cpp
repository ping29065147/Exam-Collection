static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countKDifference(vector<int>& nums, int k)
    {
        int cnt = 0;
        
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                if (abs(nums[i] - nums[j]) == k) ++cnt;
        
        return cnt;
    }
};