static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string firstPalindrome(vector<string>& words)
    {
        auto is_palindromic = [](auto& s)
        {
            for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
                if (s[i] != s[j])
                    return false;
            return true;
        };
        
        for (auto& s : words)
            if (is_palindromic(s))
                return s;
        
        return "";
    }
};