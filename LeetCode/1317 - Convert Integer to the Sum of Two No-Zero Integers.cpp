static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> getNoZeroIntegers(int n)
    {
        for (int i = 1; i < n; ++i) if (!existZero(i) && !existZero(n - i)) return {i, n - i};
        return {0, 0};
    }
    
    bool existZero(int n)
    {
        while(n)
        {
            if (n % 10 == 0) return true;
            n /= 10;
        }
        
        return false;
    }
};