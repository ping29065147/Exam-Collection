static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    double trimMean(vector<int>& arr)
    {        
        sort(arr.begin(), arr.end());
        
        int n = arr.size() / 20;
        double sum = accumulate(arr.begin() + n, arr.end() - n, 0);
        
        return sum / (arr.size() - 2 * n);
    }
};