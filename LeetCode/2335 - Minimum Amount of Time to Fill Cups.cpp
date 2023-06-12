static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int fillCups(vector<int>& amount)
    {
        sort(amount.begin(), amount.end());
        if (amount[0] + amount[1] <= amount[2]) return amount[2];
        return (amount[0] + amount[1] + amount[2] + 1) / 2;
    }
};