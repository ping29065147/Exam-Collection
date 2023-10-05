static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs)
    {
        int t = 0;
        int ID = INT_MAX, Time = 0;

        for (auto& log : logs)
        {
            int Task_Time = log[1] - t;
            if (Task_Time == Time) ID = min(ID, log[0]);
            else if (Task_Time > Time) ID = log[0], Time = Task_Time;
            t = log[1];       
        }

        return ID;
    }
};