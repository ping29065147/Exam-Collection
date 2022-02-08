static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string thousandSeparator(int n)
    {
        string s = to_string(n);        
        for (int i = s.size() - 3; i > 0; i -= 3) s.insert(s.begin() + i, '.');     
        return s;
    }
};