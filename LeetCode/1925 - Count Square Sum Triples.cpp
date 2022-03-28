static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countTriples(int n)
    {
        int cnt = 0;
        
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                int k = sqrt(i * i + j * j);             
                if (k <= n && i * i + j * j == k * k) ++cnt;
            }
        }
        
        return cnt;
    }
};