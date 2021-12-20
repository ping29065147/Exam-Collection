static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> shortestToChar(string s, char c)
    {
        vector<int> place, ret;
        
        for (int i = 0; i < s.size(); ++i) if (s[i] == c) place.push_back(i);    
        for (int i = 0; i < s.size(); ++i)
        {
            int Min = INT_MAX;
            for (auto& j : place) Min = min(Min, abs(j - i));
            ret.push_back(Min);
        }
        
        return ret;
    }
};