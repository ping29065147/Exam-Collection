static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool detectCapitalUse(string word)
    {
        int cnt = 0;
        for (auto& i : word) if (i <= 'Z') ++cnt;
        return !cnt || cnt == word.size() || (cnt == 1 && word[0] < 'Z');
    }
};