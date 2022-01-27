static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxScore(string s)
    {
        int ret = 0;
        auto getNum = [](string s, char x) {
            int cnt = 0;
            for (auto& c : s) if (c == x) ++cnt;
            return cnt;
        };
        
        for (int i = 1; i < s.size(); ++i) ret = max(ret, getNum(s.substr(0, i), '0') + getNum(s.substr(i), '1'));
        
        return ret;
    }
};