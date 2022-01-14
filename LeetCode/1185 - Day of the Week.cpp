static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year)
    {
        int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int total = 4;
        
        for (int i = 1971; i < year; ++i) total += isLeapYear(i) ? 366 : 365;
        if (isLeapYear(year)) months[2] = 29;
        for (int i = 1; i < month; ++i) total += months[i];
        total += day;
        
        return days[total % 7];
    }
    
    bool isLeapYear(int y) { return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0); }
};