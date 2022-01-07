static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums)
    {
        vector<bool> ret;        
        int n = 0;
            
        for (auto& i : nums)
        {
            n = ((n << 1) + i) % 5;
            ret.push_back(n % 5 == 0);
        }            
        
        return ret;
    }
};