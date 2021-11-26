static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration)
    {
        int ret = 0;
        int time = 0;
        
        for (auto& i : timeSeries)
        {
            if (i < time) ret -= time - i;
            time = i + duration;
            ret += duration;
        }
        
        return ret;
    }
};