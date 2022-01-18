static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findSpecialInteger(vector<int>& arr)
    {
        unordered_map<int, int> M;       
        for (auto& i : arr) if (++M[i] > arr.size() / 4) return i;
        return 0;
    }
};