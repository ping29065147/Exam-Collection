static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2)
    {
        unordered_map<char, int> M;
        
        for (auto& i : word1) ++M[i];
        for (auto& i : word2) --M[i];
        for (auto& [i, j] : M) if (abs(j) > 3) return false;
        
        return true;
    }
};