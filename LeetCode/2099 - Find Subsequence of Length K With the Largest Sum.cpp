static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k)
    {
        unordered_map<int, int> M;
        vector<int> cpy(nums);
        vector<int> V;
            
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < k; ++i) ++M[nums[i]];
        
        for (int i = 0; i < cpy.size(); ++i)
            if (--M[cpy[i]] >= 0)
                V.push_back(cpy[i]);
        
        return V;
    }
    
    
};