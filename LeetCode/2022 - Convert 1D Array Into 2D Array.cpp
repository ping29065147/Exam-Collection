static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n)
    {
        if (original.size() != m * n) return vector<vector<int>>();
        
        vector<vector<int>> V(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                V[i][j] = original[i * n + j];
        
        return V;
    }
};