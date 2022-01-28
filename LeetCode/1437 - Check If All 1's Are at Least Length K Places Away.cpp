static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k)
    {
        int cnt = 0, i = 0;
        
        while(i < nums.size() && !nums[i]) ++i;
        for (++i; i < nums.size(); ++i)
        {
            if (nums[i])
            {
                if (cnt < k) return false;
                cnt = 0;
            }
            else ++cnt;
        }
        
        return true;
    }
};