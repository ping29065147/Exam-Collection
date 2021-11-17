static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void reverseString(vector<char>& s)
    {
        reverse(s.begin(), s.end());
    }
};