static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat)
    {
        int n = mat.size();
        int cnt = 0;
        
        for (int i = 0, j = n - 1; i < n; ++i, --j)
        {
            cnt += mat[i][i];
            mat[i][i] = 0;
            cnt += mat[i][j];
        }
        
        return cnt;
    }
};