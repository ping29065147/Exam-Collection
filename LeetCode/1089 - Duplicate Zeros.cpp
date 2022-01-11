static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void duplicateZeros(vector<int>& arr)
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr[i] == 0)
            {
                arr.insert(arr.begin() + i, 0);
                arr.pop_back();
                ++i;
            }
        }
    }
};