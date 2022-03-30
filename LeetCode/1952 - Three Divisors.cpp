static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isThree(int n)
    {
        int cnt = 2;
        
        for (int i = 2; i < n; ++i)
        {
            if (n % i == 0) ++cnt;
            if (cnt > 3) return false;
        }
        return cnt == 3;
    }
};