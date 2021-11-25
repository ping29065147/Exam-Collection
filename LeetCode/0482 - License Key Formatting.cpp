static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string licenseKeyFormatting(string s, int k)
    {
        string ret;
        int cnt = 0;
        
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] != '-')
            {
                ret += toupper(s[i]);
                if (++cnt == k) ret += '-', cnt = 0;
            }
        }
        
        reverse(ret.begin(), ret.end());
        if (ret[0] == '-') ret.erase(ret.begin());
        return ret;
    }
};