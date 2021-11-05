static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        
        while(l < r)
        {

            if (!isdigit(s[l]) && !isalpha(s[l])) ++l;
            else if (!isdigit(s[r]) && !isalpha(s[r])) --r;
            else if (tolower(s[l]) != tolower(s[r])) return false;
            else ++l, --r;
        }
        
        return true;
    }
};