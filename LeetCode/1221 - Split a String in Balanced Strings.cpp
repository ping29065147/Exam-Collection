static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int balancedStringSplit(string s)
    {
        int cnt = 0, ret = 0;
        
        for (auto& c : s)
        {
            c == 'L' ? ++cnt : --cnt;
            if (!cnt) ++ret;
        }
        
        return ret;
    }
};