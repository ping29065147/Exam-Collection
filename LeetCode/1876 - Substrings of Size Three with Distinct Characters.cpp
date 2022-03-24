static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countGoodSubstrings(string s)
    {
        int cnt = 0;
        
        for (int i = 2; i < s.size(); ++i)
        {
            if (s[i] != s[i - 1] && s[i] != s[i - 2] && s[i - 1] != s[i - 2]) ++cnt;
        }
        
        return cnt;
    }
};