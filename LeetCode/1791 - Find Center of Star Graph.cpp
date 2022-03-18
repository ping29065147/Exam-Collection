static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findCenter(vector<vector<int>>& edges)
    {
        unordered_map<int, int> M;
        int n = edges.size();
        
        for (auto& v : edges) ++M[v[0]], ++M[v[1]];
        for (auto& [i, j] : M) if (j == n) return i;
        return 0;
    }
};