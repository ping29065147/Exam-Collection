static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool buddyStrings(string s, string goal)
    {
        if (s.size() != goal.size()) return false;
        if (s == goal && unordered_set<char>(s.begin(), s.end()).size() < s.size()) return true;
        
        vector<int> dif;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != goal[i]) dif.push_back(i);
        }
        
        return dif.size() == 2 && s[dif[0]] == goal[dif[1]] && s[dif[1]] == goal[dif[0]];
    }
};