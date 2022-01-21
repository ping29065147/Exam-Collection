static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int removePalindromeSub(string s)
    {
        if (s.empty()) return 0;
        else if (s == string(rbegin(s), rend(s))) return 1;
        return 2;
    }
};