static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> M;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (M.count(target - nums[i])) return {M[target - nums[i]], i};
            M[nums[i]] = i;
        }
        return{};
    }
};