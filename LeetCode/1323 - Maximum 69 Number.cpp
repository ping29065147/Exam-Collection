static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maximum69Number (int num)
    {
        string s = to_string(num);
        for (auto& c : s) if (c == '6')
        {
            c = '9';
            break;
        }
        return stoi(s);
    }
};