static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findGCD(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        return gcd(nums.back(), nums[0]);
    }
    
    int gcd(int a, int b)
    {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
};