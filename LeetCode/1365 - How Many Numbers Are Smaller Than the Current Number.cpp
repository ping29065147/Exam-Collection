static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums)
    {
        unordered_map<int, int> M;
        vector<int> V = nums, ret;
        
        sort(V.begin(), V.end());
        for (int i = 0; i < nums.size(); ++i) if (!M[V[i]]) M[V[i]] = i + 1;
        for (auto& i : nums) ret.push_back(M[i] - 1);
        
        return ret;
    }
};