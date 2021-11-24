static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool repeatedSubstringPattern(string s)
    {
        int Size = s.size();
        
        for (int i = Size / 2; i >= 1; --i) if (Size % i == 0)
        {
            int cnt = Size / i;
            string tmp;
            
            for (int j = 0; j < cnt; ++j) tmp += s.substr(0, i);
            if (tmp == s) return true;
        }
        
        return false;
    }
};