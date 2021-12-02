static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
    {
        int row = mat.size();
        int col = mat[0].size();
        
        if (row * col != r * c) return mat;
        
        vector<vector<int>> ret;
        int x = 0, y = 0;
        
        for (int i = 0; i < r; ++i)
        {
            vector<int> tmp;
            
            for (int j = 0; j < c; ++j)
            {
                if (y == col) ++x, y = 0;
                tmp.push_back(mat[x][y++]);             
            }
            
            ret.push_back(tmp);
        }
        
        return ret;
    }
};