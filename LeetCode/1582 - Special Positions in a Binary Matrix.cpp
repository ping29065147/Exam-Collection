static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat)
    {
        int r = mat.size(), c = mat[0].size(), cnt = 0;
        vector<int> row(r);
        vector<int> col(c);
        
        
        for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j)
        {
            row[i] += mat[i][j];
            col[j] += mat[i][j];
        }
        
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cnt += mat[i][j] && row[i] == 1 && col[j] == 1;
        
        return cnt;
    }
};