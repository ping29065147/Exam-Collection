static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {        
        m = grid.size();
        n = grid[0].size();
        check.resize(m + 1, vector<bool>(n + 1));
        
        for(int i = 0; i < m; ++i) for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] && !check[i][j])
            {
                cnt = 1;
                dfs(grid, i, j);
            }
        }
            
        return Max;
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y)
    {
        check[x][y] = true;
        Max = max(Max, cnt);
        
        for (int i = 0; i < 4; ++i)
        {
            int new_x = x + next[i][0];
            int new_y = y + next[i][1];
            
            if (new_x >= 0 && new_y >= 0 && new_x < m && new_y < n && !check[new_x][new_y] && grid[new_x][new_y])
            {
                ++cnt;
                dfs(grid, new_x, new_y);
            }
        }
        
    }
    
private:
    int Max = 0;
    int m, n;
    int cnt;
    int next[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> check;
};