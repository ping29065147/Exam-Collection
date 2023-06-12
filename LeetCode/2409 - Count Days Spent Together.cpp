static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        vector<int> Month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int ans = 1;

        if (leaveAlice < arriveBob || leaveBob < arriveAlice) return 0;

        string arrive = max(arriveAlice, arriveBob);
        string leave = min(leaveAlice, leaveBob);
        int arriveMonth = stoi(arrive.substr(0, 2));
        int leaveMonth = stoi(leave.substr(0, 2));
        
        ans -= (stoi(arrive.substr(3, 2)) + Month[leaveMonth] - stoi(leave.substr(3, 2)));
        ++leaveMonth;
        for (int i = arriveMonth; i < leaveMonth; ++i) ans += Month[i];      

        return ans;
    }
};