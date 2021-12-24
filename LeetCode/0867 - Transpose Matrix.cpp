static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix)
    {
        vector<vector<int>> ret;
        
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            vector<int> tmp;
            
            for (int i = 0; i < matrix.size(); ++i)
            {
                tmp.push_back(matrix[i][j]);
            }
            
            ret.push_back(tmp);
        }
        
        return ret;
    }
};