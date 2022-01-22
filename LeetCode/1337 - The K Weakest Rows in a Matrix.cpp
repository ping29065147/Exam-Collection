static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        vector<pair<int, int>> V(mat.size());
        vector<int> ret;
        
        for (int i = 0; i < mat.size(); ++i)
        {
            int cnt = 0;
            for (int j = 0; j < mat[0].size(); ++j) cnt += mat[i][j];
            V[i] = {cnt, i};
        }       
        sort(V.begin(), V.end());      
        for (int i = 0; i < k; ++i) ret.push_back(V[i].second);
        
        return ret;
    }
};