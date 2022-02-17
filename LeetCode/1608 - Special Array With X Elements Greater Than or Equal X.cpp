static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int specialArray(vector<int>& nums)
    {
        int n = nums.size();
        
        for (; n >= 0; --n)
        {
            int cnt = 0;
            for (auto& i : nums) if (i >= n) ++cnt; 
            if (cnt == n) break;
        }
        
        return n;
    }
};