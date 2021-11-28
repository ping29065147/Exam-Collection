static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1) return false;
        
        int ret = 1;    
        for (int i = 2; i <= sqrt(num); ++i) if (num % i == 0) ret += i + num / i;
        
        return ret == num;
    }
};