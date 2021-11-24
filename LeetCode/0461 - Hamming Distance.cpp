static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int hammingDistance(int x, int y)
    {
        int ret = 0;
        int t = x ^ y;
        
        while(t != 0)
        {
            if (t % 2) ++ret;
            t /= 2;
        }
        
        return ret;
    }
};