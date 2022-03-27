static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool makeEqual(vector<string>& words)
    {
        unordered_map<char, int> M;
        
        for (auto& s : words) for (auto& c : s) ++M[c];
        for (auto& [i, j] : M) if (j % words.size() != 0) return false;
        return true;
    }
};