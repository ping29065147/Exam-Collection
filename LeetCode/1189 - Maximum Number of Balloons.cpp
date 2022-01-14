static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> M;
        int ret = INT_MAX;
        
        for (auto& c : text) ++M[c];
        ret = min(ret, min(M['b'], min(M['a'], min(M['l'] / 2, min(M['o'] / 2, M['n'])))));
        
        return ret;
    }
};