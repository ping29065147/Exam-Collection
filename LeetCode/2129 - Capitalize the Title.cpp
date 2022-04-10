static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string capitalizeTitle(string title)
    {
        string ret, str;
        stringstream ss(title);
        
        while(ss >> str)
        {
            ret += (str.size() > 2 ? toupper(str[0]) : tolower(str[0]));
            for (int i = 1; i < str.size(); ++i) ret += tolower(str[i]);
            ret += " ";
        }
        ret.pop_back();
        
        return ret;
    }
};