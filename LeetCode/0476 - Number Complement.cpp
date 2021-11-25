static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findComplement(int num)
    {
        int x = 1;
        for (long long i = 2; x < num; i *= 2) x += i;
        
        return num ^ x;
    }
};