static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0) return false;
        
        long x1 = x, x2 = 0;
        
        for (; x; x /= 10) x2 = x2*10 + x%10;
        return x1 == x2;
    }
};