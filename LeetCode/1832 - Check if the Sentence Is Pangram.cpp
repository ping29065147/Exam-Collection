static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool checkIfPangram(string sentence)
    {
        unordered_map<char, int> M;
        for (auto& c : sentence) ++M[c];
        return M.size() == 26;
    }
};