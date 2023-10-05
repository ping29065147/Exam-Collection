static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int commonFactors(int a, int b)
    {
        unordered_set<int> S;
        int Min = min(a, b), Max = max(a, b);
        int n = sqrt(Min);       
        int ans = 0;

        for (int i = 1; i <= n; ++i)
            if (Min % i == 0)
            {
                S.insert(i);
                S.insert(Min / i);
            }
        
        for (auto& i : S)
            if (Max % i == 0)
                ++ans;

        return ans;
    }
};