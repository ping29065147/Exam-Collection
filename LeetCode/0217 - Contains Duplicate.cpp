static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_map<int, int> M;
        
        for (auto& i : nums)
        {
            if (M.count(i)) return true;
            ++M[i];
        }
        
        return false;
    }
};