static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int myAtoi(string s)
    {
        bool negative = false;
        long long num = 0;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ') continue;
            else if (isdigit(s[i]) || s[i] == '+' || s[i] == '-')
            {
                if (s[i] == '-') negative = true, ++i;
                else if (s[i] == '+') ++i;
                if (!isdigit(s[i])) break;
                
                do{
                    if (num > INT_MAX) break;
                    num = num * 10 + (s[i] - '0');
                }
                while(isdigit(s[++i]));
                
                if (negative) num = -num;
                if (num > INT_MAX) num = INT_MAX;
                else if (num < INT_MIN) num = INT_MIN;
                
                return num;
            }
            else break;
        }
        
        return 0;
    }
};