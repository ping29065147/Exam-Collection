static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findLucky(vector<int>& arr)
    {
        unordered_map<int, int> M;
        int ret = -1;
        
        for (auto& i : arr) ++M[i];
        for (auto& [i, j] : M) if (i == j) ret = max(ret, i);
        
        return ret;
    }
};