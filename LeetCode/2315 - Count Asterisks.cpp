static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countAsterisks(string s)
    {
        int ans = 0, x = 1;

        for (auto& c : s)
        {
            if (c == '|') x ^= 1;
            else if (x && c == '*') ++ans;
        }

        return ans;
    }
};