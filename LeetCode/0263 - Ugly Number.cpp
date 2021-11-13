static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isUgly(int n)
    {
        if (n <= 0) return false;
        while(n % 2 == 0) n /= 2;
        while(n % 3 == 0) n /= 3;
        while(n % 5 == 0) n /= 5;
        return (n == 1 ? true : false);
    }
};