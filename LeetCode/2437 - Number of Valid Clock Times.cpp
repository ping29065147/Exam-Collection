static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countTime(string time)
    {
        int h = 1, m = 1;

        if (time[0] == '?' && time[1] == '?') h = 24;
        else if (time[0] == '?' && time[1] != '?') h = (time[1] <= '3' ? 3 : 2);
        else if (time[0] != '?' && time[1] == '?') h = (time[0] == '2' ? 4 : 10);

        if (time[3] == '?' && time[4] == '?') m = 60;
        else if (time[3] == '?' && time[4] != '?') m = (time[4] == 0 ? 7 : 6);
        else if (time[3] != '?' && time[4] == '?') m = (time[3] == 6 ? 1 : 10);

        return h * m;
    }
};