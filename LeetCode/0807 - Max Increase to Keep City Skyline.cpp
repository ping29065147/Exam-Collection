static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
    {
        vector<int> V1, V2;
        int cnt = 0;
        
        for (int i = 0; i < grid.size(); ++i)
        {
            int t1 = 0, t2 = 0;
            
            for (int j = 0; j < grid[0].size(); ++j)
            {
                t1 = max(t1, grid[i][j]);
                t2 = max(t2, grid[j][i]);
            }
            
            V1.push_back(t1);
            V2.push_back(t2);
        }
        
        for (int i = 0; i < V1.size(); ++i)
            for (int j = 0; j < V2.size(); ++j)
                cnt += min(V1[i], V2[j]) - grid[i][j];
        
        return cnt;
    }
};