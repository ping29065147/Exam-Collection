static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles)
    {
        unordered_map<int, int> M;
        int m = 0;
        
        for (auto& v : rectangles)
        {
            m = max(m, min(v[0], v[1]));
            ++M[min(v[0], v[1])];
        }
        
        return M[m];
    }
};