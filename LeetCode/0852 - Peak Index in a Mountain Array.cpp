static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int index = 0, val = 0;
        
        for (int i = 0; i < arr.size(); ++i) if (arr[i] > val) 
        {
            index = i;
            val = arr[i];
        }
        
        return index;
    }
};