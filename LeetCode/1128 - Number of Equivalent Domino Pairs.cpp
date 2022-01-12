static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes)
    {
        unordered_map<int, int> M;
        int cnt = 0;
        
        for (auto& i : dominoes)
        {
            if (i[0] > i[1]) swap(i[0], i[1]);
            ++M[i[0] * 10 + i[1]];
        }     
        for (auto& [i, j] : M) if (j >= 2) cnt += (j - 1) * j / 2;
        
        return cnt;
    }
};