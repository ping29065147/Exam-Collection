static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        unordered_map<int, int> M, t;
        
        for (auto& i : arr) ++M[i];
        for (auto& [i, j] : M) if (++t[j] > 1) return false;
        
        return true;
    }
};