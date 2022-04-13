static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countPairs(vector<int>& nums, int k)
    {
        int n = nums.size(), cnt = 0;
        
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (nums[i] == nums[j] && (i * j) % k == 0)
                    ++cnt;
        
        return cnt;
    }
};