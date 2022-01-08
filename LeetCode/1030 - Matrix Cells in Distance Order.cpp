static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
    {
        vector<vector<int>> ret;
        
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                ret.push_back({ i, j });
        
        sort(ret.begin(), ret.end(), [rCenter, cCenter](auto& a, auto& b){
            return abs(a[0] - rCenter) + abs(a[1] - cCenter) < abs(b[0] - rCenter) + abs(b[1] - cCenter);
        });
        
        return ret;
    }
};