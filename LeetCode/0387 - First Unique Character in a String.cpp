static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> M;
        
        for (auto& c : s) ++M[c];    
        for (int i = 0; i < s.size(); ++i) if (M[s[i]] == 1) return i;
        
        return -1;
    }
};