static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d)
    {
        int cnt = 0;
        
        for (auto& i : arr1)
        {
            for (auto& j : arr2) if (abs(i - j) <= d)
            {
                ++cnt;
                break;
            }
        }
        
        return arr1.size() - cnt;
    }
};