static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int titleToNumber(string columnTitle)
    {
        int ret = 0;
        
        for (long long i = columnTitle.size() - 1, j = 1; i >= 0; --i, j *= 26)
        {
            ret += (columnTitle[i] - 'A' + 1) * j;
        }
        
        return ret;
    }
};