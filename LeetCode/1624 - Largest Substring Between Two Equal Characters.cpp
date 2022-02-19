static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        int cnt = -1;
        unordered_map<char, int> M;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (M.count(s[i])) cnt = max(cnt, i - M[s[i]] - 1);
            else M[s[i]] = i;
        }
        
        return cnt;
    }
};