static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string toHex(int num)
    {
        if (!num) return "0";
        
        string ret;
        string str = "0123456789abcdef";
        long long Lnum = num < 0 ? (1LL << 32) + num : num;
        
        while(Lnum > 0)
        {
            ret.insert(ret.begin(), str[Lnum % 16]);
            Lnum /= 16;
        }
        
        return ret;
        
    }
};