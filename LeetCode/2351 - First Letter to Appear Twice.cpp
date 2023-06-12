static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    char repeatedCharacter(string s)
    {
        unordered_map<char, int> M;

        for (auto& c : s) if (++M[c] == 2) return c;

        return ' ';
    }
};