static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int getMaximumGenerated(int n)
    {
        vector<int> V(n + 1, 0);
        int m = 0;
        
        if (n) V[1] = 1, m = 1;
        for (int i = 2; i <= n; ++i)
        {
            if (i % 2) V[i] = V[(i - 1) / 2] + V[(i - 1) / 2 + 1];
            else V[i] = V[i / 2];
            m = max(m, V[i]);
        }
        
        return m;
    }
};