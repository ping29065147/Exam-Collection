static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string reversePrefix(string word, char ch)
    {
        auto it = word.find(ch);
        
        if (it != string::npos)
            reverse(word.begin(), word.begin() + it + 1);
        
        return word;
    }
};