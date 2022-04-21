static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minBitFlips(int start, int goal)
    {
        int cnt = 0;
        
        while(start || goal)
        {
            cnt += (start & 1) ^ (goal & 1);
            start >>= 1, goal >>= 1;
        }
        
        return cnt;
    }
};