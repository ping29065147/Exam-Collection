static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) 
    {
        unordered_map<int, int> M;
        vector<vector<int>> ans;

        for (auto& i : items1) M[i[0]] += i[1];
        for (auto& i : items2) M[i[0]] += i[1];
        for (auto& [i, j] : M) ans.push_back({i, j});
        sort(ans.begin(), ans.end());

        return ans;
    }
};