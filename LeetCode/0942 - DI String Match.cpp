static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> diStringMatch(string s)
    {
        vector<int> V;
        int st = 0, ed = s.size();
        
        for (auto& c : s)
        {
            if (c == 'I') V.push_back(st++);
            else V.push_back(ed--);
        }
        
        V.push_back(ed);
        return V;
    }
};