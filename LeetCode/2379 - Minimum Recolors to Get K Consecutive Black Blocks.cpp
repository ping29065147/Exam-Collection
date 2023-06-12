static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minimumRecolors(string blocks, int k)
    {
        int ans = 0, t;

        for (int i = 0; i < k; ++i) ans += (blocks[i] == 'W');
        for (int i = k, t = ans; i < blocks.size(); ++i)
        {
            t += (blocks[i] == 'W') - (blocks[i - k] == 'W');
            ans = min(ans, t);
        }

        return ans;
    }
};