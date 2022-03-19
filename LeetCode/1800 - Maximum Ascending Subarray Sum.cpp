static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxAscendingSum(vector<int>& nums)
    {
        int ret = 0, sum = 0, cur = 0;
        
        for (auto& i : nums)
        {
            sum = (i > cur ? sum + i : i);
            cur = i;
            ret = max(ret, sum);
        }
        
        return ret;
    }
};