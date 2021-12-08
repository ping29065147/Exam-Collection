static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img)
    {
        int m = img.size();
        int n = img[0].size();        
        vector<vector<int>> ret = img;
        vector<vector<int>> dirs{{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
        
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j)
        {
            int cnt = img[i][j];
            int item = 1;
            
            for (auto& dir : dirs)
            {
                int x = i + dir[0];
                int y = j + dir[1];
                
                if (x >= 0 && x < m && y >= 0 && y < n)
                {
                    ++item;
                    cnt += img[x][y];
                }
                
                ret[i][j] = cnt / item;
            }
        }
        
        return ret;
    }
};