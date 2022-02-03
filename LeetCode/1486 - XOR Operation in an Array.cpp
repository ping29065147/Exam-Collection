static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();


class Solution {
public:
    int xorOperation(int n, int start)
    {
        int ret = 0;
        for (int i = 0; i < n; ++i) ret ^= start + 2 * i;
        return ret;
    }
};