static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countPoints(string rings)
    {
        int cnt = 0;
        set<char> S[10];
        
        for (int i = 0; i < rings.size(); i += 2) S[rings[i + 1] - '0'].insert(rings[i]);   
        for (int i = 0; i < 10; ++i) if (S[i].size() == 3) ++cnt;
        
        return cnt;
    }
};