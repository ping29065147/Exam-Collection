static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> M;
        vector<vector<string>> ans;
        
        for (auto& s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            M[t].push_back(s);
        }
        
        for (auto& [i, j] : M)
        {
            vector<string> V;
            for (auto& s : j) V.push_back(s);
            ans.push_back(V);
        }
        
        return ans;
    }
};