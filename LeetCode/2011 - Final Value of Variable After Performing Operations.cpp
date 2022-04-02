static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations)
    {
        int x = 0;
        
        for (auto& s : operations)
        {
            if (s == "++X" || s == "X++") ++x;
            else --x;
        }
        
        return x;
    }
};