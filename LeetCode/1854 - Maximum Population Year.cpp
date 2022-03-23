static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs)
    {
        vector<pair<int, int>> V;
        int m = 0, cnt = 0, y = 0;
        
        for (auto& i : logs) V.push_back({ i[0], 1 }), V.push_back({ i[1], -1 });
        sort(V.begin(), V.end());
        
        for (auto& [i, j] : V)
        {
            cnt += j;
            if (cnt > m) m = cnt, y = i;
        }
        
        return y;
    }
};