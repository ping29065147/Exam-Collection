static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class NumArray {
public:
    NumArray(vector<int>& nums)
    {
        dp = nums;
        for (int i = 1; i < nums.size(); ++i) dp[i] += dp[i - 1];
    }
    
    int sumRange(int left, int right)
    {
        return (left == 0 ? dp[right] : dp[right] - dp[left - 1]);
    }
    
private:
    vector<int> dp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */