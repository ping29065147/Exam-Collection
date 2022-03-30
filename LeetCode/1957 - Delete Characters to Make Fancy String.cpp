static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string makeFancyString(string s)
    {
        string ret;
        int cnt = 0;
        
        for (auto& c : s)
        {
            if (ret.empty() || c != ret.back()) cnt = 1;
            else if (++cnt >= 3) continue;
            ret += c;
        }
        
        return ret;
    }
};