static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students)
    {
        int cnt = 0;
        
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        for (int i = 0; i < seats.size(); ++i) cnt += abs(seats[i] - students[i]);
        
        return cnt;
    }
};