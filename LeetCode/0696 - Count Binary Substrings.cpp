static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countBinarySubstrings(string s)
    {
        int ret = 0;
        
        for (int i = 1, pre = 0, cur = 1; i < s.size(); ++i)
        {
            if (s[i] == s[i - 1]) ++cur;
            else pre = cur, cur = 1;
            if (pre >= cur) ++ret;
        }
        
        return ret;
    }
};