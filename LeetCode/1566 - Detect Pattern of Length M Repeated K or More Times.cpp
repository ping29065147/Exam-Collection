static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k)
    {
        for (int i = 0, cnt = 0; i + m < arr.size(); ++i)
        {
            if (arr[i] != arr[i + m]) cnt = 0;
            else if (++cnt == (k - 1) * m) return true;
        }
        
        return false;
    }
};