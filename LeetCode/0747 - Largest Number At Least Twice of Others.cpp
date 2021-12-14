static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int dominantIndex(vector<int>& nums)
    {
        int S = nums.size();
        if (S == 1) return 0;
        unordered_map<int, int> M;
        
        for(int i = 0; i < S; ++i) M[nums[i]] = i;
        sort(nums.begin(), nums.end());
        
        return nums[S - 1] >= nums[S - 2] * 2 ? M[nums[S - 1]] : -1;
    }
};