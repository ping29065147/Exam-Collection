static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int bitwiseComplement(int n)
    {
        int x = 1;
        
        while(n > x - 1) x *= 2;
        
        return n ? x - n - 1 : 1;
    }
};