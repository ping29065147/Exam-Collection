static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string interpret(string command)
    {
        unordered_map<string, string> M = {{"G", "G"}, {"()", "o"}, {"(al)", "al"}};
        string str, ret;
        
        for (auto& c : command)
        {
            str += c;
            if (M.count(str)) ret += M[str], str = "";
        }
        
        return ret;
    }
};