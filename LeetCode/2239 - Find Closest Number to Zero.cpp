static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findClosestNumber(vector<int>& nums)
    {
        int n = INT_MAX;
        for (auto& i : nums)
            if (abs(i) < abs(n)) n = i;
            else if (abs(i) == abs(n)) n = max(i, n);
        return n;
    }
};