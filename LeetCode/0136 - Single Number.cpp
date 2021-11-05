static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int ret = 0;        
        for (auto& i : nums) ret ^= i;
        return ret;
    }
};