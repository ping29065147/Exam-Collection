static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        
        for (int i = 0; i < n; ++i)
        {
            set<int> S1, S2;
            for (int j = 0; j < n; ++j)
            {
                S1.insert(matrix[i][j]);
                S2.insert(matrix[j][i]);
            }
            if (S1.size() != n || S2.size() != n) return false;
        }
        
        return true;
    }
};