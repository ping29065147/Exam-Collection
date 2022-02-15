static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();


class Solution {
public:
    string reorderSpaces(string text)
    {
        int cnt = 0, n = 0;
        stringstream ss(text);
        string str, ret, space;
        vector<string> V;
        
        for (auto& c : text) if (c == ' ') ++cnt;
        while(ss >> str) V.push_back(str);
        n = V.size() <= 1 ? 0 : cnt / (V.size() - 1);
        for (int i = 0; i < n; ++i) space += ' ';
        
        for (auto& i : V)
        {
            ret += i;
            if (cnt >= n)
            {
                ret += space;
                cnt -= n;
            }
        }
        for (int i = 0; i < cnt; ++i) ret += ' ';
        
        return ret;
    }
};