static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries)
    {
        vector<int> V, ans;
        int cnt = 0;

        sort(nums.begin(), nums.end());
        for (auto& i : nums)
        {
            cnt += i;
            V.push_back(cnt);
        }

        for (int i = 0; i < queries.size(); ++i)
        {
            ans.push_back(upper_bound(V.begin(), V.end(), queries[i]) - V.begin());
        }

        return ans;
    }
};