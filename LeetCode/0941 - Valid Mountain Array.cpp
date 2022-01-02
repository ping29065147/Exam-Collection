static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool validMountainArray(vector<int>& arr)
    {
        if (arr.size() < 3) return false;
        
        int up = false, swt = false;
        for (int i = 1; i < arr.size(); ++i)
        {
            if (!swt)
            {
                if (arr[i] < arr[i - 1]) swt = true;
                else if (arr[i] == arr[i - 1]) return false;
                else up = true;
            }
            else
            {
                if (arr[i] >= arr[i - 1]) return false;
            }
        }
        
        return up && swt;
    }
};