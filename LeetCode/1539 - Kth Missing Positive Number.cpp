static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k)
    {
        for (auto& i : arr) if (i <= k) ++k;
        return k;
    }
};