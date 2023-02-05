static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> findArray(vector<int>& pref)
    {
        int n = pref.size();
        vector<int> ans(n, 0);
        ans[0] = pref[0];
        
        for (int i = 1; i < n; ++i)
            ans[i] = pref[i - 1] ^ pref[i];
        
        return ans;
    }
};