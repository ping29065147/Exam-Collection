static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int top = 0, front = 0, side = 0;
        
        for (int i = 0; i < n; ++i)
        {
            int t1 = 0;
            int t2 = 0;
            
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j]) ++top;
                t1 = max(t1, grid[i][j]);
                t2 = max(t2, grid[j][i]);
            }
            
            front += t1;
            side += t2;
        }
        
        return top + front + side;
    }
};