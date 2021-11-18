static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ret;
        
        for (auto& i : nums1)
        {
            auto x = find(nums2.begin(), nums2.end(), i);
            if (x != nums2.end())
            {
                ret.push_back(i);
                nums2.erase(x);
            }
        }
    
        return ret;
    }
};