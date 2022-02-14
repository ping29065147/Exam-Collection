static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string modifyString(string s)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != '?') continue;
            
            if (i == 0) s[i] = s[i + 1] == 'a' ? 'b' : 'a';
            else if (i == s.size() - 1) s[i] = s[i - 1] == 'a' ? 'b' : 'a';
            else
            {
                if (s[i - 1] != 'a' && s[i + 1] != 'a') s[i] = 'a';
                else if (s[i - 1] != 'b' && s[i + 1] != 'b') s[i] = 'b';
                else s[i] = 'c';
            }
        }
        
        return s;
    }
};