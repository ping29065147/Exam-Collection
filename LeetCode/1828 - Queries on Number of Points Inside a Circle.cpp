static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries)
    {
        vector<int> ans;
        
        for (auto& i : queries)
        {
            int cnt = 0;
            
            for (auto& j : points)
                if (pow(pow(i[0] - j[0], 2) + pow(i[1] - j[1], 2), 0.5) <= i[2])
                    ++cnt;
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};