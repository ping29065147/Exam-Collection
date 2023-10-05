static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string oddString(vector<string>& words)
    {
        vector<vector<int>> V;
        int cnt = 1;
        string ans = words[0];

        for (int i = 0; i < words.size(); ++i)
        {            
            vector<int> t;
            for (int j = 1; j < words[i].size(); ++j) t.push_back(words[i][j] - words[i][j - 1]);

            if (V.empty()) V.push_back(t);
            else if (t == V[0]) ++cnt;
            else ans = words[i];
        }

        return cnt == 1 ? words[0] : ans;
    }
};