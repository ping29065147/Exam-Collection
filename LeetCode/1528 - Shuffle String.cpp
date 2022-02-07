static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string restoreString(string s, vector<int>& indices)
    {
        string ret = s;       
        for (int i = 0; i < s.size(); ++i) ret[indices[i]] = s[i];
        return ret;
    }
};