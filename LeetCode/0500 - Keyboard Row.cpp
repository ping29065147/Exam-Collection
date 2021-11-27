static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> findWords(vector<string>& words)
    {
        vector<string> ret;
        string str[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        
        for (auto& j : words) 
        {
            int cnt[3]{};
            
            for (auto& i : j)
            {
                for (int k = 0; k < 3; ++k) if (count(str[k].begin(), str[k].end(), i)) cnt[k] = 1;
                if (cnt[0] + cnt[1] + cnt[2] > 1) break;
            }
            
            if (cnt[0] + cnt[1] + cnt[2] == 1) ret.push_back(j);
        }
        
        return ret;
    }
};