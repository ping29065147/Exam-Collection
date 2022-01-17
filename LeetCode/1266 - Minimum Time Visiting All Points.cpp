static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points)
    {
        int cnt = 0;
        
        for (int i = 1; i < points.size(); ++i)
        {
            int x = abs(points[i][0] - points[i - 1][0]);
            int y = abs(points[i][1] - points[i - 1][1]);
            
            cnt += max(x, y);
        }
        
        return cnt;
    }
};