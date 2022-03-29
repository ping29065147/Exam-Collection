static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool areOccurrencesEqual(string s)
    {
        unordered_map<char, int> M;
        
        for (auto& c : s) ++M[c];
        int n = M[s[0]];
        for (auto& [i, j] : M) if (j != n) return false;
        return true;
    }
};