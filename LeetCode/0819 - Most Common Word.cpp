static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned)
    {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> M;
        stringstream ss;
        string tmp, ret;
        int Max = 0;
        
        for (auto& c : paragraph) c = (isalpha(c) ? tolower(c) : ' ');
        ss << paragraph;
        while(ss >> tmp)
        {
            if (!ban.count(tmp) && ++M[tmp] > Max) Max = M[tmp], ret = tmp;   
        }
        
        return ret;
    }
};