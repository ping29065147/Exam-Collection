static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int distributeCandies(vector<int>& candyType)
    {
        unordered_set<int> S;
        
        for (auto& i : candyType) S.insert(i);
        
        return candyType.size() / 2 <= S.size() ? candyType.size() / 2 : S.size();
    }
};