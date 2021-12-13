static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        if (image[sr][sc] == newColor) return image;
        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int pre)
    {
        image[sr][sc] = newColor;
        
        for (int i = 0; i < 4; ++i)
        {
            int Newsr = sr + next[i][1];
            int Newsc = sc + next[i][0];
            if (Newsr < 0 || Newsc < 0 || Newsr >= image.size() || Newsc >= image[0].size()) continue;
            if (image[Newsr][Newsc] == pre) dfs(image, Newsr, Newsc, newColor, pre);
        }
    }
    
private:
    int next[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};