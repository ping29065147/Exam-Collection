static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums)
    {
        unordered_map<int, int> M;
        
        for (auto& i : nums) ++M[i];
        sort(nums.begin(), nums.end(), [&](auto a, auto b){
            return M[a] != M[b] ? M[a] < M[b] : a > b;
        });
            
        return nums;
    }
};