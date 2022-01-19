static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr)
    {
        vector<int> ret(arr.size(), -1);
        int m = arr.back();
        
        for (int i = arr.size() - 2; i >= 0; --i)
        {
            ret[i] = m;
            m = max(m, arr[i]);
        }
        
        return ret;
    }
};