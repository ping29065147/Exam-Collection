static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isPathCrossing(string path)
    {
        unordered_map<char, pair<int, int>> S = {{'N', {0, 1}}, {'S', {0, -1}}, {'W', {-1, 0}}, {'E', {1, 0}}};
        unordered_map<string, int> M;
        pair<int, int> cur = {0, 0};
        ++M["0 0"];
        
        for (auto& c : path)
        {
            cur.first += S[c].first;
            cur.second += S[c].second;
            string s = to_string(cur.first) + " " + to_string(cur.second);
            if (++M[s] == 2) return true;
        }
        
        return false;
    }
};