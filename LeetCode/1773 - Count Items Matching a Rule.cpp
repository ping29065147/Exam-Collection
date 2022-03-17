static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue)
    {
        int it = 0, cnt = 0;;
        
        if (ruleKey == "color") it = 1;
        else if (ruleKey == "name") it = 2;      
        for (auto& v : items) if (v[it] == ruleValue) ++cnt;
        
        return cnt;
    }
};