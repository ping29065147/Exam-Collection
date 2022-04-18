static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> cellsInRange(string s)
    {
        vector<string> V;
        
        for (char i = s[0]; i <= s[3]; ++i)
        {
            for (char j = s[1]; j <= s[4]; ++j)
            {
                string str(1, i);
                str += j;
                V.push_back(str);
            }
        }
        
        return V;
    }
};