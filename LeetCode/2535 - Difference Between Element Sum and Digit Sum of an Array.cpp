static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int differenceOfSum(vector<int>& nums)
    {
        int ans = 0;

        for (auto& i : nums)
        {
            ans += i;
            while(i) ans -= i % 10, i /= 10;
        }

        return abs(ans);
    }
};