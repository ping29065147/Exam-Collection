static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        int n = mat.size();
        if (mat == target) return true;
        for (int i = 0; i < 3; ++i) if (rotate(mat, n) == target) return true;   
        return false;
    }
    
    vector<vector<int>> rotate(vector<vector<int>>& mat, int n)
    {
        for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) swap(mat[i][j], mat[j][i]);     
        for (int j = 0; j < n; ++j)  for (int i = 0; i < n / 2; ++i) swap(mat[i][j], mat[n - i - 1][j]);
        
        return mat;
    }
};