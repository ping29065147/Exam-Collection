static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string generateTheString(int n)
    {
        return n % 2 ? string(n, 'a') : string(n - 1, 'a') + "b";
    }
};