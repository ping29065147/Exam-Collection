static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string longestPalindrome(string s)
    {
        string s2 = s;
        int start = 0, cnt = 1;
        
        reverse(begin(s2), end(s2));
        if (s.size() == 1 || s2 == s) return s;
        
        for (int i = 1; i < s.size(); ++i)
        {
            if (i - cnt - 1 >= 0)
            {
                string odd = s.substr(i - cnt - 1, cnt + 2);
                string odd2 = odd;
                reverse(begin(odd2), end(odd2));
                if (odd == odd2)
                {
                    start = i - cnt - 1;
                    cnt += 2;
                }
            }
            if (i - cnt >= 0)
            {
                string even = s.substr(i - cnt, cnt + 1);
                string even2 = even;
                reverse(begin(even2), end(even2));
                if (even == even2)
                {
                    start = i - cnt;
                    ++cnt;
                }
            }
        }
        
        return s.substr(start, cnt);
    }
};