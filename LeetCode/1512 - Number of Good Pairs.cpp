static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        int cnt = 0;    
        for (int i = 0; i < nums.size(); ++i) cnt += count(nums.begin() + i + 1, nums.end(), nums[i]);      
        return cnt;
    }
};