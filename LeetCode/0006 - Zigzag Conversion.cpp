static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1) return s;
        
        int dif = numRows * 2 - 2;
        string str;
        
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = i, x = 0; j < s.size(); x ^= 1)
            {
                str = str + s[j];
                if (!i || i == numRows - 1) j += dif;
                else if (x) j += i * 2;
                else j += (dif - i * 2);
            }
        }
        
        return str;
    }
};