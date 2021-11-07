static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        unordered_map<int, int> M;
        
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (M.count(target - numbers[i])) return { M[target - numbers[i]], i + 1 };
            M[numbers[i]] = i + 1;
        }
        return {};
    }
};