static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int arrangeCoins(int n)
    {
        int cnt = 0;
        
        for (int s = 1; n >= s; ++s) n -= s, ++cnt;
        
        return cnt;
    }
};