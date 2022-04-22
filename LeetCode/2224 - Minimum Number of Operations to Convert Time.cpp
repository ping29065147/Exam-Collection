static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int convertTime(string current, string correct)
    {
        int cnt = 0;
        int n = (correct[0] - current[0]) * 600 + (correct[1] - current[1]) * 60 + (correct[3] - current[3]) * 10 + (correct[4] - current[4]);
        
        cnt += (n / 60), n %= 60;
        cnt += (n / 15), n %= 15;
        cnt += (n / 5), n %= 5;
        cnt += n;
        
        return cnt;
    }
};