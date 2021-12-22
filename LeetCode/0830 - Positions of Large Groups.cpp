static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        vector<vector<int>> ret;
        int ptr = 0, cnt = 0;
        char cur;
        
        for (int i = 0; i < s.size();)
        {
            ptr = i;
            cur = s[i];
            while(s[++i] == cur) ++cnt;
            
            if (cnt >= 2) ret.push_back({ptr, ptr + cnt});              
            cnt = 0;
        }
        
        return ret;
    }
};