static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k)
    {
        unordered_map<string, int> M;
        
        for (auto& i : arr) ++M[i];
        for (auto& i : arr)
        {
            if (M[i] == 1) --k;
            if (k == 0) return i;
        }
        
        return "";
    }
};