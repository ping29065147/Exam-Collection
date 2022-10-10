static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n - i; ++j)
                swap(matrix[i][j], matrix[n - 1 - j][m - 1 - i]);
        
        for (int i = 0; i < m / 2; ++i)
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[m - 1 - i][j]);
    }
};