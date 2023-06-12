static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int mostFrequentEven(vector<int>& nums)
    {
        unordered_map<int, int> M;
        int ans = -1, cnt = 0;

        for (auto& i :nums) ++M[i];
        for (auto& [i, j] : M)
        {
            if (i % 2) continue;
            if (j > cnt) ans = i, cnt = j;
            else if (j == cnt) ans = min(ans, i);
        }

        return ans;
    }
};