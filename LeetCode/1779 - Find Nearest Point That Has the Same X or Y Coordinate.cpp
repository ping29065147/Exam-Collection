static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points)
    {
        int m = INT_MAX, index = INT_MAX;
        
        for (int i = 0; i < points.size(); ++i)
        {
            if (points[i][0] == x || points[i][1] == y)
            {
                int dis = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (dis < m) m = dis, index = i; 
            }
        }
        
        return index == INT_MAX ? -1 : index;
    }
};