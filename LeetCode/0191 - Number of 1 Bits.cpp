static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int ret = 0;
        
        for (int i = 0; i < 32; ++i)
        {
            ret += n & 1;
            n >>= 1;
        }
        
        return ret;
    }
};