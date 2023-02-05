static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums)
    {
        unordered_map<int, int> M;
        vector<int> res;
        
        for (auto& num : nums)
            for (auto& i : num)
                if (++M[i] == nums.size())
                    res.push_back(i);
        
        sort(res.begin(), res.end());
        
        return res;
    }
};