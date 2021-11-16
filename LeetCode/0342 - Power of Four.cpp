static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0) return false;
        
        while(n != 1)
        {
            if (n % 4 != 0) return false;
            n /= 4;
        }
        
        return true;
    }
};