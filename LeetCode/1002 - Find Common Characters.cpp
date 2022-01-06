static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> commonChars(vector<string>& words)
    {
        vector<int> V(26, INT_MAX);
        vector<string> ret;
        
        for (auto& w : words)
        {
            vector<int> tmp(26, 0);
            for (auto& c : w) ++tmp[c - 'a'];
            for (int i = 0; i < 26; ++i) V[i] = min(V[i], tmp[i]);
        }
        
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < V[i]; ++j)
                ret.push_back(string(1, i + 'a'));
        
        return ret;
    }
};