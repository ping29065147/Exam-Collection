static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> constructRectangle(int area)
    {
        int x = sqrt(area);
        while(area % x) --x;
        return {area / x, x};
    }
};