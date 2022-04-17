static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key)
    {
        unordered_map<int, int> M;
        int cnt = 0, n = 0;
        
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i - 1] == key)
                if (++M[nums[i]] > cnt)
                {
                    cnt = M[nums[i]];
                    n = nums[i];
                }
        
        return n;
    }
};