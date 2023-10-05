static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findMaxK(vector<int>& nums)
    {
        unordered_map<int, int> M;
        int ans = -1;

        for (auto& i :nums)
        {
            if (M[-i]) ans = max(ans, abs(i));
            M[i] = 1;
        }

        return ans;
    }
};