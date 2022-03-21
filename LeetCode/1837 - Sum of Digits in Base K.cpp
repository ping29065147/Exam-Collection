static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int sumBase(int n, int k)
    {
        int cnt = 0;
        while(n) cnt += n % k, n /= k;
        return cnt;
    }
};