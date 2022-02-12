static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds)
    {
        unordered_map<int, int> M;
        vector<int> ret;
        int m = 0;
        
        for (int i = 1; i < rounds.size(); ++i)
        {
            int st = rounds[i - 1];
            while(st != rounds[i])
            {
                m = max(m, ++M[st++]);
                if (st > n) st = 1;
            }
        }
        m = max(m, ++M[rounds.back()]);        
        for (auto& [i, j] : M) if (j == m) ret.push_back(i);
        sort(ret.begin(), ret.end());
        
        return ret;
    }
};