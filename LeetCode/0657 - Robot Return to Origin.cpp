static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool judgeCircle(string moves)
    {
        unordered_map<char, int> M = {{'R', 1}, {'L', -1}, {'U', 20000}, {'D', -20000}};
        int sum = 0;
        
        for(auto& c : moves) sum += M[c];
        
        return sum == 0;
    }
};