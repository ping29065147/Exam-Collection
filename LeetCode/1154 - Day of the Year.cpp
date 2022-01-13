static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int dayOfYear(string date)
    {
        int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
        int cnt = 0;
        int M = stoi(date.substr(5, 6));
        int D = stoi(date.substr(8));
        
        if (leapYear(stoi(date.substr(0, 4)))) m[2] = 29;
        for (int i = 1; i < M; ++i) cnt += m[i];
        cnt += D;
        
        return cnt;
    }
    
    bool leapYear(int y)
    {
        return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
    }
};