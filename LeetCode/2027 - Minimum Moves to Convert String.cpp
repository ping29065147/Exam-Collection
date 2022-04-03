static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minimumMoves(string s)
    {
        int cnt = 0;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'X')
            {
                ++cnt;
                i += 2;
            }
        }
        
        return cnt;
    }
};