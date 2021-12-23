static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        string tmp1;
        for (auto& c : s)
        {
            if (c == '#')
            {
                if (!tmp1.empty()) tmp1.pop_back();
            }
            else tmp1.push_back(c);
        }
        
        string tmp2;
        for (auto& c : t)
        {
            if (c == '#')
            {
                if (!tmp2.empty()) tmp2.pop_back();
            }
            else tmp2.push_back(c);
        }
        
        return tmp1 == tmp2;
    }
};