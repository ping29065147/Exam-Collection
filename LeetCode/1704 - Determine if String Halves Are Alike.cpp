static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool halvesAreAlike(string s)
    {
        unordered_map<char, int> M = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}, {'A', 1}, {'E', 1}, {'I', 1}, {'O', 1}, {'U', 1}};
        int cnt = 0, S = s.size();
        
        for (int i = 0; i < S; ++i)
        {
            if (i < S / 2) cnt += M[s[i]];
            else cnt -= M[s[i]];
        }
        
        return !cnt;
    }
};