static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> sumZero(int n)
    {
        vector<int> ret(n);
        int m = 0;
        
        for (int i = 1; i < n; ++i) ret[i - 1] = i, m += i;
        ret[n - 1] = -m;
        
        return ret;
    }
};