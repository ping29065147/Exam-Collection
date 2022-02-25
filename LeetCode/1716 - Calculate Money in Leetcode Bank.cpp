static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int totalMoney(int n)
    {
        int w = 0, cnt = 0;
        
        while(n >= 7)
        {
            cnt += 28 + 7 * w++;
            n -= 7;
        }
        
        cnt += n * (1 + n) / 2 + n * w;
        
        return cnt;
    }
};