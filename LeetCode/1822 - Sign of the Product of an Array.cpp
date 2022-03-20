static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int arraySign(vector<int>& nums)
    {
        int x = 0;
        
        for (auto& i : nums)
        {
            if (!i) return 0;
            if (i < 0) x ^= 1;
        }
        
        return x ? -1 : 1;
    }
};