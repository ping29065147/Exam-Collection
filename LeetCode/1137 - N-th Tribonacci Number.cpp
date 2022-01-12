static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int tribonacci(int n)
    {
        vector<int> V(n + 3);
        
        V[0] = 0, V[1] = V[2] = 1;
        for (int i = 3; i <= n; ++i) V[i] = V[i - 1] + V[i - 2] + V[i - 3];
        
        return V[n];
    }
};