static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool checkString(string s)
    {
        string s2(s);
        sort(s2.begin(), s2.end());
        return s == s2;
    }
};