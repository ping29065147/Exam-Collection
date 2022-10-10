static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isStrictlyPalindromic(int n)
    {
        return isBasePalindromic(n, 2);
    }
    
    bool isBasePalindromic(int n, int b)
    {
        if (b > n - 2) return true;
        
        return isPalindromic(n, b) && isBasePalindromic(n, b + 1);
    }
    
    bool isPalindromic(int n, int b)
    {
        string s, t;
        
        while(n)
        {
            s.insert(0, 1, (n % b) + '0');
            n /= b;
        }
        
        t = s;
        reverse(t.begin(), t.end());
        
        return s == t;
    }
};