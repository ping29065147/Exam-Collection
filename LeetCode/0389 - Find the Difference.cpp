static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    char findTheDifference(string s, string t)
    {
        unordered_map<char, int> M;
        
        for (auto& c : s) ++M[c];    
        for (auto& c : t)
        {
            if (M[c] == 0) return c;
            else --M[c];
        }
        return 0;
    }
};