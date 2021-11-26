static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ret;
        
        for (auto& i : nums1)
        {
            auto it = find(nums2.begin(), nums2.end(), i);
            int tmp = *it;
            
            for (++it; it != nums2.end(); ++it)
            {
                if (*it > tmp)
                {
                    ret.push_back(*it);
                    break;
                }
            }
            
            if (it == nums2.end()) ret.push_back(-1);
        }
        
        return ret;
    }
};