static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
            
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] < 0)
                {
                    cnt += n - j;
                    break;
                }
            }
        }
        
        return cnt;
    }
};