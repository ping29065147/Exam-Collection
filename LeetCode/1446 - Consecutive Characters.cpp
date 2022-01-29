static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxPower(string s)
    {
        int ret = 0, it = 0;
        
        for (int i = 0; i < s.size();)
        {
            while(s[++it] == s[i]);
            ret = max(ret, it - i);
            i = it;
        }
        
        return ret;
    }
};