static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> v1, v2, ret(n);
        
        for (int i = 0; i < n; ++i)
        {
            if (i % 2) v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        }
        
        sort(v1.begin(), v1.end(), greater<int>());
        sort(v2.begin(), v2.end());
        
        for (int i = 0; i < v2.size(); ++i) ret[i * 2] = v2[i];
        for (int i = 0; i < v1.size(); ++i) ret[i * 2 + 1] = v1[i];

        return ret;
    }
};