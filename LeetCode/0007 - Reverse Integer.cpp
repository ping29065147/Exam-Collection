static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int reverse(int x)
    {
        string s = to_string(x);        
        std::reverse(s.begin(), s.end());
        
        long long y = stol(s);
        bool ne = (x < 0);
        
        if (y > INT_MAX) return 0;
        else if (ne) return -y;
        return y;
    }
};