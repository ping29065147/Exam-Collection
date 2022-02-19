static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed)
    {
        int t = 0, cnt = 0;
        char ret;
        
        for (int i = 0; i < releaseTimes.size(); ++i)
        {
            if (releaseTimes[i] - t > cnt) cnt = releaseTimes[i] - t, ret = keysPressed[i];
            else if (releaseTimes[i] - t == cnt && keysPressed[i] > ret) ret = keysPressed[i];
            t = releaseTimes[i];
        }
        
        return ret;
    }
};