static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findNumbers(vector<int>& nums)
    {
        int cnt = 0;
        for (auto& i : nums) if (to_string(i).size() % 2 == 0) ++cnt;
        return cnt;
    }
};