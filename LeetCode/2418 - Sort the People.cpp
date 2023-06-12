static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        vector<pair<int, string>> V;
        vector<string> ans;

        for (int i = 0; i < names.size(); ++i) V.push_back({heights[i], names[i]});

        sort(V.begin(), V.end(), [](pair<int, string> a, pair<int, string> b){
            return a.first > b.first;
        });

        for (auto& [i, j]: V) ans.push_back(j);

        return ans;
    }
};