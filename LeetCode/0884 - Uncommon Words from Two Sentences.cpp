static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        s1 += " " + s2;
        
        unordered_map<string, int> M;
        stringstream ss(s1);
        string str;
        vector<string> V;
        
        while(ss >> str) ++M[str];
        for (auto& [i, j] : M) if (j < 2) V.push_back(i);
        
        return V;
    }
};