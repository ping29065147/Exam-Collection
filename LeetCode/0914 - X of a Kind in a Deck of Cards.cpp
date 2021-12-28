static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck)
    {
        unordered_map<int, int> M;
        int ret = 0;
        
        for (auto& i : deck) ++M[i];
        for (auto& [i, j] : M) ret = gcd(ret, j);
        
        return ret > 1;
    }
};