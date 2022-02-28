static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string longestNiceSubstring(string s)
    {
        int n = s.size();    
        string ans;
        
        for (int i = 0; i < n; ++i)
        {
            vector<int> u(26), l(26);
            
            for (int j = i; j < n; ++j)
            {
                char c = s[j];
                
                if (isupper(c)) u[c - 'A'] = 1;
                else l[c - 'a'] = 1;
                
                if (u == l && j - i + 1 > ans.size()) ans = s.substr(i, j - i + 1);
            }
        }
        return ans;
    }
};