static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool squareIsWhite(string coordinates)
    {
        int l1 = coordinates[0] - 'a' + 1;
        int l2 = coordinates[1] - '0';
        return l1 % 2 != l2 % 2;
    }
};