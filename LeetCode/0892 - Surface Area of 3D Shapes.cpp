static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid)
    {
        int ret = 0;
        
        for (int i = 0; i < grid.size(); ++i) for (int j = 0; j < grid.size(); ++j)
        {
            if (grid[i][j] > 0) ret += grid[i][j] * 4 + 2;
            if (i > 0) ret -= min(grid[i][j], grid[i - 1][j]) * 2;
            if (j > 0) ret -= min(grid[i][j], grid[i][j - 1]) * 2;
        }
        
        return ret;
    }
};