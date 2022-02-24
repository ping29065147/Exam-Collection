static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numberOfMatches(int n)
    {
        int cnt = 0;
        
        while(n != 1)
        {
            cnt += n / 2;
            if (n % 2) n = n / 2 + 1;
            else n = n / 2;
        }
        
        return cnt;
    }
};