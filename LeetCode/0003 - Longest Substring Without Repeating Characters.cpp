static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> M;
        int cnt = 0, it = 0;
        
        for (int i = 0; i < s.size(); ++i)
        {
            ++M[s[i]];
            while(M[s[i]] > 1) --M[s[it++]];
            int t = 0;
            for (auto& [i, j] : M) t += (j > 0);
            cnt = max(cnt, t);
        }
        
        return cnt;
    }
};