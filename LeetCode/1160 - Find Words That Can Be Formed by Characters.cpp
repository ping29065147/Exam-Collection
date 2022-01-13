static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countCharacters(vector<string>& words, string chars)
    {
        unordered_map<char, int> M;
        int cnt = 0;
        
        for (auto& c : chars) ++M[c];
        for (auto& s : words)
        {
            unordered_map<char, int> t = M;
            
            for (auto& c : s) if (--t[c] < 0)
            {
                cnt -= s.size();
                break;
            }
            
            cnt += s.size();
        }
        
        return cnt;
    }
};