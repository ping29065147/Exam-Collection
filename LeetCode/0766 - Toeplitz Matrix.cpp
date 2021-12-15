static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i = 1; i < m; ++i) for (int j = 1; j < n; ++j)
        {
            if (matrix[i - 1][j - 1] != matrix[i][j]) return false;
        }
        
        return true;
    }
};