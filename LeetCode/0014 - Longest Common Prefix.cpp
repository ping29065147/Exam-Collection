static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        sort(strs.begin(), strs.end());
        int i = 0, l = min(strs[0].size(), strs.back().size());
        while (i < l && strs[0][i] == strs.back()[i]) ++i;
        return strs[0].substr(0, i);
    }
};