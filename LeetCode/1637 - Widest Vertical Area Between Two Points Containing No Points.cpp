static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points)
    {
        vector<int> V;
        int ans = 0;
        
        for (auto& i : points)
            V.push_back(i[0]);
        
        sort(V.begin(), V.end());
        
        for (int i = 1; i < V.size(); ++i)
            ans = max(ans, V[i] - V[i - 1]);
        
        return ans;
    }
};