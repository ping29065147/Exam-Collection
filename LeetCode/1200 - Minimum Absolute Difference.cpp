static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr)
    {
        vector<vector<int>> ret;
        int Min = INT_MAX;
        
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); ++i) Min = min(Min, arr[i] - arr[i - 1]);
        for (int i = 1; i < arr.size(); ++i) if (arr[i] - arr[i - 1] == Min) ret.push_back({ arr[i - 1], arr[i] });
        
        return ret;
    }
};