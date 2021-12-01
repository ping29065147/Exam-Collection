static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string tmp;
        string ret;
        
        while(ss >> tmp)
        {
            reverse(tmp.begin(), tmp.end());
            ret += tmp + ' ';
        }
        ret.pop_back();
        
        return ret;
    }
};