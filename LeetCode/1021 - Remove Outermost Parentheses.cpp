static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string removeOuterParentheses(string s)
    {
        int cnt = 0;
        string ret, tmp;
        
        for (auto& c : s)
        {
            c == '(' ? ++cnt : --cnt;
            
            if (!cnt)
            {
                ret += tmp.substr(1);
                cnt = 0;
                tmp = "";
            }
            else tmp += c;            
        }
        
        return ret;
    }
};