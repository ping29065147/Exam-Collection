static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        int i = 0, m = min(word1.size(), word2.size());
        string ret;
        
        for (; i < m; ++i)
        {
            ret += word1[i];
            ret += word2[i];
        }
        ret += word1.size() < word2.size() ? word2.substr(m) : word1.substr(m);
        
        return ret;
    }
};