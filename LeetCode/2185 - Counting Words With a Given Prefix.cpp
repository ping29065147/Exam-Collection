static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int prefixCount(vector<string>& words, string pref)
    {
        int cnt = 0;
        
        for (auto& s : words)
            if (s.find(pref) != string::npos && s.find(pref) == 0)
                ++cnt;
        
        return cnt;
    }
};