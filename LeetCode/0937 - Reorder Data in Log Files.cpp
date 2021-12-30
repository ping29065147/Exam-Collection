static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs)
    {
        vector<string> ret, digit;
        vector< pair<string, string> > alpha;
        
        for (auto& s : logs)
        {
            auto it = s.find(' ');
            if (isdigit(s[it + 1])) digit.push_back(s);
            else alpha.push_back( {s.substr(0, it), s.substr(it)} );
        }
        
        sort(alpha.begin(), alpha.end(), [](auto& a, auto& b) 
             { return a.second < b.second || (a.second == b.second && a.first < b.first); });
        
        for (auto& s : alpha) ret.push_back(s.first + s.second);
        for (auto& s : digit) ret.push_back(s);
        
        return ret;
    }
};