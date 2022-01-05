static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board)
    {
        int p[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int cnt = 0;
        
        for (int i = 0; i < 8; ++i) for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] == 'R')
            {
                for (int k = 0; k < 4; ++k)
                {
                    int x = i + p[k][0];
                    int y = j + p[k][1];
                    
                    while(x >= 0 && x < 8 && y >= 0 && y < 8)
                    {
                        if (board[x][y] == 'p')
                        {
                            ++cnt;
                            break;
                        }
                        else if (board[x][y] == 'B') break;
                        
                        x += p[k][0], y += p[k][1];
                    }
                }
                
                break;
            }
        }
        
        return cnt;
    }
};