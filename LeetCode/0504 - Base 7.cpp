static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string convertToBase7(int num)
    {
        if (!num) return "0";
        
        string str;
        bool minus = false;
        
        if (num < 0) num *= -1, minus = true;
        while(num != 0)
        {
            str += to_string(num % 7);
            num /= 7;
        }
        reverse(str.begin(), str.end());
        if (minus) str = '-' + str;
        
        return str;
    }
};