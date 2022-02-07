static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string makeGood(string s)
    {
        for (int i = 1; i < s.size(); ++i)
        {
            if (abs(s[i] - s[i - 1]) == 32)
            {
                s.erase(s.begin() + i);
                s.erase(s.begin() + i - 1);
                i = 0;
            }
        }
        
        return s;
    }
};