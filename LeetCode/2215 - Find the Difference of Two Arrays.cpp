static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans1, ans2;
        unordered_map<int, int> M1, M2;
        
        for (auto& i : nums1) ++M1[i];
        for (auto& i : nums2) ++M2[i];
        
        for (auto& [i, j] : M1) if (!M2[i]) ans1.push_back(i);
        for (auto& [i, j] : M2) if (!M1[i]) ans2.push_back(i);
        
        return {ans1, ans2};
    }
};