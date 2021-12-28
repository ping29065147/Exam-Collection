static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string reverseOnlyLetters(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
        {
            while(i < j && !isalpha(s[i])) ++i;
            while(i < j && !isalpha(s[j])) --j;
            swap(s[i], s[j]);
        }
        
        return s;
    }
};