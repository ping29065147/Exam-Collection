static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums)
    {
        int S = nums.size();
        int i = 0, j = 1;
        
        while(i < S && j < S)
        {
            if (nums[i] % 2 == 0) i += 2;
            else if (nums[j] % 2) j += 2;
            else swap(nums[i], nums[j]);
        }
        
        return nums;
    }
};