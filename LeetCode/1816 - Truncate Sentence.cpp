static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string truncateSentence(string s, int k)
    {
        stringstream ss(s);
        string str, ret;
        
        while(k--)
        {
            ss >> str;
            ret += str + ' ';
        }
        ret.pop_back();
        
        return ret;
    }
};