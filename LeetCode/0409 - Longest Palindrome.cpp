static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int longestPalindrome(string s)
    {
        unordered_set<char> T;
        
        for (auto& c : s)
        {
            if (!T.count(c)) T.insert(c);
            else T.erase(c);
        }
        
        return s.size() - (T.empty() ? 0 : T.size() - 1);
    }
};