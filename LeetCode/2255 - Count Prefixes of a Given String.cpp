static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countPrefixes(vector<string>& words, string s)
    {
        int cnt = words.size();
        
        for (auto& w : words)
            for (int i = 0; i < w.size(); ++i)
                if (w[i] != s[i])
                {
                    --cnt;
                    break;
                }
        
        return cnt;
    }
};