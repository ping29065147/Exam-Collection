static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid)
    {
        int n = grid.size() - 2;
        vector<vector<int>> res(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int x = i; x < i + 3; ++x)
                    for (int y = j; y < j + 3; ++y)
                        res[i][j] = max(res[i][j], grid[x][y]);
        
        return res;
    }
};