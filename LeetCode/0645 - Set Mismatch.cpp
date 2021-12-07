static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        int sum = 0;
        int S = nums.size();
        vector<bool> ch(S);
        vector<int> ret;
        
        for (int i = 0; i < S; ++i)
        {
            if (ch[nums[i]]) ret.push_back(nums[i]);
            ch[nums[i]] = true;
            sum += i - nums[i] + 1;
        }
        ret.push_back(sum + ret[0]);
        
        return ret;
    }
};