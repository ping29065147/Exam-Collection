static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves)
    {
        vector<vector<int>> V(3, vector<int>(3, -10));
        int p = 1;
        
        for (auto& i : moves)
        { 
            V[i[0]][i[1]] = p;
            p ^= 1;
        }
        
        for (int i = 0; i < 3; ++i)
        {
            if (V[i][0] + V[i][1] + V[i][2] == 3) return "A";
            else if (V[0][i] + V[1][i] + V[2][i] == 3) return "A";
            else if (V[i][0] + V[i][1] + V[i][2] == 0) return "B";
            else if (V[0][i] + V[1][i] + V[2][i] == 0) return "B";           
        }
        if (V[0][0] + V[1][1] + V[2][2] == 3) return "A";
        else if (V[0][0] + V[1][1] + V[2][2] == 0) return "B";
        else if (V[2][0] + V[1][1] + V[0][2] == 3) return "A";
        else if (V[2][0] + V[1][1] + V[0][2] == 0) return "B";
        
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};