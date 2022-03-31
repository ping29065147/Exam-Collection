static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words)
    {
        string str;
        
        for (auto& i : words) 
        {
            str += i;
            if (str == s) return true;
        }
        
        return false;
    }
};