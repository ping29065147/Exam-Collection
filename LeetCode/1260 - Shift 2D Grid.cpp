static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        int l = m * n;
        vector<vector<int>> V(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int idx = (i * n + j + k) % l;
                V[idx / n][idx % n] = grid[i][j];
            }
        }
        
        return V;
    }
};