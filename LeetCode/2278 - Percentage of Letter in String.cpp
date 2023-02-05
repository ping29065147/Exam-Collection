static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int percentageLetter(string s, char letter)
    {
        return count(s.begin(), s.end(), letter) * 100.0 / s.size() ;
    }
};