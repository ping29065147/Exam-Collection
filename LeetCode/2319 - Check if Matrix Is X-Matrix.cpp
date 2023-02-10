static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid)
    {
        for (int i = 0, j = grid.size() - 1; i < grid.size(); ++i, --j)
        {
            if (grid[i][i] == 0 || grid[i][j] == 0) return false;
            grid[i][i] = grid[i][j] = 0;
        }

        for (auto& i : grid)
            for (auto& j : i)
                if (j) return false;

        return true;
    }
};