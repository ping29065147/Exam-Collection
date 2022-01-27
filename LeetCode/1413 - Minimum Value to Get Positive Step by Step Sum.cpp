static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minStartValue(vector<int>& nums)
    {
        int Min = INT_MAX, cnt = 0;
        
        for (auto& i : nums)
        {
            cnt += i;
            Min = min(Min, cnt);
        }
        
        return Min < 0 ? -Min + 1 : 1;
    }
};