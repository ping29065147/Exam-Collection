static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countOdds(int low, int high)
    {
        return ((high % 2 ? high : high - 1) - (low % 2 ? low : low + 1)) /2 + 1;
    }
};