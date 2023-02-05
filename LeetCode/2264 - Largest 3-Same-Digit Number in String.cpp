static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string largestGoodInteger(string num)
    {
        string ans = "0";

        for (int i = 2; i < num.size(); ++i)
        {
            if (num[i - 2] == num[i - 1] && num[i - 1] == num[i])
            {
                string t = num.substr(i - 2, 3);
                ans = max(ans, t);
            }
        }

        return ans == "0" ? "" : ans;
    }
};