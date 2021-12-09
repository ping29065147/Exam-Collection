static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool hasAlternatingBits(int n)
    {
        int d = n & 1;    
        while((n & 1) == d) d ^= 1, n >>= 1;
        return n == 0;
    }
};