static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int col = grid.size();
        int row = grid[0].size();
        int ret = 0;
        
        for (int i = 0; i < col; ++i) for (int j = 0; j < row; ++j)
        {
            if (!grid[i][j]) continue;
            
            ret += 4;
            if (i > 0 && grid[i - 1][j]) ret -= 2;
            if (j > 0 && grid[i][j - 1]) ret -= 2;
        }
        
        return ret;
    }
};