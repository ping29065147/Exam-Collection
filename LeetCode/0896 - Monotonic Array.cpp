static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isMonotonic(vector<int>& nums)
    {
        vector<int> a = nums;
        vector<int> b = nums;
        
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end());
        
        return a == nums || b == nums;
    }
};