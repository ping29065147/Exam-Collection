static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int romanToInt(string s)
    {
        int ret = 0;
        char tmp = 'M';
        unordered_map<char, int> dict = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        for (auto& c : s)
        {
            ret += dict[c];
            if (dict[tmp] < dict[c]) ret -= dict[tmp] * 2;
            tmp = c;
        }
        
        return ret;
    }
};