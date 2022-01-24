static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix)
    {
        unordered_map<int, int> M;
        vector<int> ret;
        
        for (auto& i : matrix) ++M[*min_element(i.begin(), i.end())];
        for (int i = 0; i < matrix[0].size(); ++i)
        {
            int Max = matrix[0][i];
            for (int j = 1; j < matrix.size(); ++j) Max = max(Max, matrix[j][i]);
            if (M[Max]) ret.push_back(Max);
        }
        
        return ret;
    }
};