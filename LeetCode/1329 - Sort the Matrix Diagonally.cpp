static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
    {
        int n = mat[0].size(), m = mat.size();
        vector<deque<int>> V(m + n);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                V[i - j + n].push_back(mat[i][j]);

        for (auto& v : V) sort(v.begin(), v.end());

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                mat[i][j] = V[i - j + n].front(), V[i - j + n].pop_front();

        return mat;
    }
};