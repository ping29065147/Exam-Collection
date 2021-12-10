static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findShortestSubArray(vector<int>& nums)
    {
        int degree = 0;
        unordered_map<int, int> M;
        unordered_map<int, pair<int, int>> pos;
        int ret = INT_MAX;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (++M[nums[i]] == 1) pos[nums[i]] = {i, i};
            else pos[nums[i]].second = i;
            degree = max(degree, M[nums[i]]);
        }
        
        for (auto& [i, j] : M) if (degree == j)
        {
            ret = min(ret, pos[i].second - pos[i].first + 1);
        }
        
        return ret;
    }
};