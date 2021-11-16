static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0) return false;
        
        while(n != 1)
        {
            if (n % 3 != 0) return false;
            n /= 3;
        }
        return true;
    }
};