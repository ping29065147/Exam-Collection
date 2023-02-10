static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income)
    {
        double ans = 0;

        for (int i = 0; i < brackets.size(); ++i)
        {
            int t = (i ? min(income, brackets[i][0] - brackets[i - 1][0]) : min(income, brackets[i][0]));
            ans += t * brackets[i][1] * 0.01;
            income -= t;
        }

        return ans;
    }
};