static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool digitCount(string num)
    {
        for (int i = 0; i < num.size(); ++i)
            if (count(num.begin(), num.end(), i + '0') != num[i] - '0')
                return false;

        return true;
    }
};