static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s)
    {
        int line = 1, sum = 0;
        
        for (auto& c : s)
        {
            int t = widths[c - 'a'];
            if (sum + t > 100) sum = t, ++line;
            else sum += t;
        }
        
        return {line, sum};
    }
};