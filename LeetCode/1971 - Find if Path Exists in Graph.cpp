static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {   
        V.resize(n);
        for (auto& i : edges) M[i[0]].push_back(i[1]), M[i[1]].push_back(i[0]);
        return dfs(source, destination);
    }
    
    bool dfs(int s, int d)
    {
        if (s == d) return true;
        if (V[s]) return false;
        
        V[s] = true;        
        bool t = false;
        
        for (auto& i : M[s]) t |= dfs(i, d);
        
        return t;
    }

private:
    unordered_map<int, vector<int>> M;
    vector<bool> V;
};