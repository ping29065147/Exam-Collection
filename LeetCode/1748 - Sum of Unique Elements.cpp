static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int sumOfUnique(vector<int>& nums)
    {
        unordered_map<int, int> M;
        int cnt = 0;
        
        for (auto& i : nums) ++M[i];
        for (auto& [i, j] : M) if (j == 1) cnt += i;
        
        return cnt;
    }
};