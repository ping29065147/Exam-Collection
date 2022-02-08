static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr)
    {
        for (int i = 2; i < arr.size(); ++i)
            if (arr[i] % 2 && arr[i - 1] % 2 && arr[i - 2] % 2)
                return true;      
        return false;
    }
};