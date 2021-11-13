static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());     
        return s == t;
    }
};