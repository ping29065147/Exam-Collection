static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();


class Solution {
public:
    double average(vector<int>& salary)
    {
        sort(salary.begin(), salary.end());
        return (double)accumulate(salary.begin() + 1, salary.end() - 1, 0) / (salary.size() - 2);
    }
};