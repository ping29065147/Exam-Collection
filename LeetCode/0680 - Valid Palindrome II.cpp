static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool validPalindrome(string s)
    {
        int x = 0, y = s.size() - 1;
        
        while (x < y)
        {
            if (s[x] != s[y]) return check(s, x + 1, y) || check(s, x, y - 1);         
            ++x, --y;
        }
        
        return true;
    }
    
    bool check(string s, int x, int y)
    {
        while(x < y) if (s[x++] != s[y--]) return false;
        return true;
    }
};