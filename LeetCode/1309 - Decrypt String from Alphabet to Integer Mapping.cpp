static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string freqAlphabets(string s)
    {
        string ret;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (i + 2 < s.size() && s[i + 2] == '#')
            {
                ret += stoi(s.substr(i, 2)) + 'a' - 1;
                i += 2;
            }
            else ret += (s[i] - '0') + 'a' - 1;
        }
        
        return ret;
    }
};