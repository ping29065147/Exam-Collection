static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int smallestEvenMultiple(int n)
    {
        return n & 1 ? n << 1 : n;
    }
};