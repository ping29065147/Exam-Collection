static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countEven(int num)
    {
        int cnt = 0;        
        for (int i = 2; i <= num; ++i) if (is_even(i)) ++cnt;
        return cnt;
    }
    
    bool is_even(int n)
    {
        int cnt = 0;
        while(n) cnt += n % 10, n /= 10;
        return cnt % 2 == 0;
    }
};