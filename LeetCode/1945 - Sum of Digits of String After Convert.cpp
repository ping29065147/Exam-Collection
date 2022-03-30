static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int getLucky(string s, int k)
    {
        string str;
        
        for (auto& c : s) str += to_string(c - 'a' + 1);
        while(k--)
        {
            int num = 0;
            for (auto& c : str) num += c - '0';
            str = to_string(num);
        }
        
        return stoi(str);
    }
};