static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int cnt = 0;
        int i = 0, j = height.size() - 1;
        
        while(i < j)
        {
            cnt = max(cnt, min(height[i], height[j]) * (j - i));
            height[i] < height[j] ? ++i : --j;
        }
        
        return cnt;
    }
};