static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countBalls(int lowLimit, int highLimit)
    {
        unordered_map<int, int> M;
        int cnt = 0;
        
        for (int i = lowLimit; i <= highLimit; ++i) cnt = max(cnt, ++M[getNum(i)]);
        
        return cnt;
    }
    
    int getNum(int n)
    {
        int cnt = 0;
        while(n) cnt += n % 10, n /= 10;
        return cnt;
    }
};