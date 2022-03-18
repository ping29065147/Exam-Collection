static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int secondHighest(string s)
    {
        set<int, greater<int>> S;
        
        for (auto& c : s) if (isdigit(c)) S.insert(c - '0');
        auto it = S.begin();
        
        return S.size() > 1 ? *++it : -1;
    }
};