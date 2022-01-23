static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr)
    {
        sort(arr.begin(), arr.end(), [](auto& a, auto& b){
           return __builtin_popcount(a) <  __builtin_popcount(b) || (__builtin_popcount(a) ==  __builtin_popcount(b) && a < b);
        });
        
        return arr;
    }
};