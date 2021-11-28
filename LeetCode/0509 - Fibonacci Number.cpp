static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int fib(int n)
    {
        vector<int> F(max(2, n + 1));
        F[0] = 0; F[1] = 1;
        
        for (int i = 2; i <= n; ++i) F[i] = F[i - 1] + F[i - 2];
        return F[n];
    }
};