static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3)
    {
        unordered_map<int, int> M;
        vector<int> V;
        
        for (auto& i : nums1) ++M[i];
        for (auto& i : nums2) M[i] += 101;
        for (auto& i : nums3) M[i] += 1000;
        for (auto& [i, j] : M)
            if (j > 101 && j % 101 && j % 1000)
                V.push_back(i);
        
        return V;
    }
};