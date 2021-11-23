static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        vector<int> ret;
        vector<bool> check(nums.size() + 1);
        
        for (int i = 0; i < nums.size(); ++i) check[nums[i]] = true;        
        for (int i = 1; i < check.size(); ++i) if (!check[i]) ret.push_back(i);
        
        return ret;
    }
};