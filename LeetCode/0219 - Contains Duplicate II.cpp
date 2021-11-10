static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int, int> M;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (M.count(nums[i]) && i - M[nums[i]] <= k) return true;
            M[nums[i]] = i;
        }
        
        return false;
    }
};