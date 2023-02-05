static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k)
    {
        sort(score.begin(), score.end(), [&](vector<int> &a, vector<int> &b){
            return a[k] > b[k];
        });

        return score;
    }
};