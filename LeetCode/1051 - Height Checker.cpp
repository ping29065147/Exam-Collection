static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int heightChecker(vector<int>& heights)
    {
        vector<int> V = heights;
        int cnt = 0;
        
        sort(V.begin(), V.end());
        for (int i = 0; i < V.size(); ++i) if (V[i] != heights[i]) ++cnt;
        
        return cnt;
    }
};