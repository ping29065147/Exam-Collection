static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxDepth(string s)
    {
        int cnt = 0;
        stack<int> S;
        
        for (auto& c : s)
        {
            if (c == '(') S.push('(');
            else if (c == ')') cnt = max(cnt, (int)S.size()), S.pop();
        }
        
        return cnt;
    }
};