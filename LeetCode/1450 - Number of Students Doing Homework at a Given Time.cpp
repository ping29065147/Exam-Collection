static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime)
    {
        int cnt = 0;
        
        for (int i = 0; i < startTime.size(); ++i)
        {
            if (startTime[i] <= queryTime && queryTime <= endTime[i]) ++cnt;
        }
        
        return cnt;
    }
};