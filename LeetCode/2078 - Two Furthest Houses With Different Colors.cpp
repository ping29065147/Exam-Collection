static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxDistance(vector<int>& colors)
    {
        int cnt = 0;
        
        for (int i = 0; i < colors.size(); ++i)
            for (int j = i + 1; j < colors.size(); ++j)
                if (colors[i] != colors[j])
                    cnt = max(cnt, j - i);
        
        return cnt;
    }
};