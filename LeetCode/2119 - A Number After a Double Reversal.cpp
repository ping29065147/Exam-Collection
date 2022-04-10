static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isSameAfterReversals(int num)
    {
        if (num == 0) return true;
        if (num % 10 == 0) return false;        
        while(num > 10) num /= 10;        
        return num ? true : false;
    }
};