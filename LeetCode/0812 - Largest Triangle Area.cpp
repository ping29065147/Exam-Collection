static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points)
    {
        double ret = 0;
        
        for (auto& i : points) 
            for (auto& j : points)
                for (auto& k : points)
                {
                    ret = max(ret, 0.5 * abs(i[0] * j[1] + j[0] * k[1] + k[0] * i[1] - j[0] * i[1] - k[0] * j[1] - i[0] * k[1]));
                }
        
        return ret;
    }
};