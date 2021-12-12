static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string toLowerCase(string s)
    {
        for (auto& c : s) c = tolower(c);
        return s;
    }
};