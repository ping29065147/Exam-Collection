static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int mostWordsFound(vector<string>& sentences)
    {
        int cnt = 0;
        string str;
        
        for (auto& s : sentences)
        {
            stringstream ss(s);
            int t = 0;
            
            while(ss >> str) ++t;
            cnt = max(cnt, t);
        }
        
        return cnt;
    }
};