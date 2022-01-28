static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string destCity(vector<vector<string>>& paths)
    {
        unordered_map<string, string> M;
        string str = paths[0][0];
        
        for (auto& s : paths) M[s[0]] = s[1];
        while(1)
        {
            if (M.find(str) == M.end()) break;
            str = M[str];
        }
        
        return str;
    }
};