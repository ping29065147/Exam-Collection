static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countLargestGroup(int n)
    {
        unordered_map<int, int> M;
        int m = 0, cnt = 0;
        
        auto sum = [](auto x) { 
                int t = 0;
                while(x) t += x % 10, x /= 10;
                return t;
            };
        
        for (int i = 1; i <= n; ++i) m = max(m, ++M[sum(i)]);
        for (auto& [i, j] : M) if (j == m) ++cnt;
        
        return cnt;
    }
};