static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ret;
        
        for (auto& i : nums1)
        {
            if (find(nums2.begin(), nums2.end(), i) != nums2.end() && find(ret.begin(), ret.end(), i) == ret.end()) ret.push_back(i);
        }
        
        return ret;
    }
};