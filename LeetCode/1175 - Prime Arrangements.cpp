static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numPrimeArrangements(int n)
    {
        vector<bool> p(n + 1, true);
        int cnt = 0;
        long long m = 1e9 + 7, ret = 1;
        
        p[0] = p[1] = false;
        for (int i = 2; i * i <= n; ++i)
        {
            if (p[i])
            {
                for (int j = i * 2; j <= n; j += i)
                    p[j] = false;
            }
        }
        
        for (int i = 1; i <= n; ++i) if (p[i]) ++cnt;
        for (int i = 1; i <= cnt; ++i) ret = ret * i % m;
        for (int i = 1; i <= n - cnt; ++i) ret = ret * i % m;
        
        return ret;
    }
};