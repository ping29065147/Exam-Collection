static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        vector<int> V(n + 1, 0);
        pair<int, int> judge = {1, 0};
        
        for (auto& i : trust)
        {
            V[i[0]] -= 1000;
            ++V[i[1]];
        }
        
        for (int i = 1; i < V.size(); ++i)
        {
            if (V[i] > judge.second) judge = {i, V[i]};
        }
        
        return judge.second == n - 1 ? judge.first : -1;
    }
};