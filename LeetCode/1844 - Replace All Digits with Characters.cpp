static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string replaceDigits(string s)
    {
        for (int i = 1; i < s.size(); i += 2) s[i] = s[i - 1] + (s[i] - '0');
        return s;
    }
};