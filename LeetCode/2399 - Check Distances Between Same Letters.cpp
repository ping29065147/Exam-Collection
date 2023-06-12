static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = i + 1; j < s.size(); ++j)
            {
                if (s[i] != s[j]) continue;
                if (distance[s[i] - 'a'] != j - i - 1) return false;
            }
        }

        return true;
    }
};