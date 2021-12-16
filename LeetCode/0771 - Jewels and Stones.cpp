static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_map<char, bool> M;
        int cnt = 0;
        
        for (auto& c : jewels) M[c] = true;
        for (auto& c : stones) if (M[c]) ++cnt;
        
        return cnt;
    }
};