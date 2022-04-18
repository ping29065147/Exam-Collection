static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k)
    {
        vector<int> keys, V;
        
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == key)
                keys.push_back(i);
        
        for (int i = 0; i < nums.size(); ++i)
            for (auto& j : keys)
                if (abs(i - j) <= k)
                {
                    V.push_back(i);
                    break;
                }                    
        
        return V;
    }
};