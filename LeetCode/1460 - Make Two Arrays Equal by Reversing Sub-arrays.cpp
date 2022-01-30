static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr)
    {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        
        return target == arr;
    }
};