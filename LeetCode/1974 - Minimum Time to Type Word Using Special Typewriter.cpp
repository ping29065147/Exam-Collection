static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minTimeToType(string word)
    {
        int cnt = word.size();
        char cur = 'a';
        
        for (auto& c : word)
        {
            cnt += min(abs(cur - c), 26 - abs(cur - c)); 
            cur = c;
        }
        
        return cnt;
    }
};