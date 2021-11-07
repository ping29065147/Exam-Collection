static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string convertToTitle(int columnNumber)
    {
        string ret;
        
        while(columnNumber > 0)
        {
            ret.insert(ret.begin(), ((columnNumber - 1) % 26) + 'A');
            columnNumber = (columnNumber - 1) / 26;
        }
        
        return ret;
    }
};