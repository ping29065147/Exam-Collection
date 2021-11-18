static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    
    bool isPerfectSquare(int num)
    {
        for (int i = 1; i <= num / i; ++i)
        {
            if (i * i == num) return true;
        }
        
        return false;
    }
    
};