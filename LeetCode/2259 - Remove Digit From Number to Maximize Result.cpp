static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string removeDigit(string number, char digit)
    {
        string ans = "0";

        for (int i = 0; i < number.size(); ++i)
        {
            if (digit == number[i])
            {
                string t = number;
                t.erase(t.begin() + i);
                ans = max(ans, t);
            }
        }

        return ans;
    }
};