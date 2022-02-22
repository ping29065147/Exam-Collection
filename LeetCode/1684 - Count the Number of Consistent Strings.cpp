static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words)
    {
        unordered_map<char, bool> M;
        int cnt = 0;
        
        for (auto& c : allowed) M[c] = true;
        for (auto& s : words) cnt += all_of(s.begin(), s.end(), [&M](auto c){ return M[c]; });
        
        return cnt;
    }
};