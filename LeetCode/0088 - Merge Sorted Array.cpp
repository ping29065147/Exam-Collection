static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        for (int i = m; i < m + n; ++i) nums1[i] = nums2[i - m];
        sort(nums1.begin(), nums1.end());
    }
};