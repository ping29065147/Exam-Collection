static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score)
    {
        int Size = score.size();
        vector<string> ret(Size);
        priority_queue< pair<int, int> > PQ;
        
        for (int i = 0; i < Size; ++i) PQ.push({score[i], i});
        for (int cnt = 1; cnt <= Size; ++cnt)
        {
            auto [i, j] = PQ.top(); PQ.pop();
            if (cnt == 1) ret[j] = "Gold Medal";
            else if (cnt == 2) ret[j] = "Silver Medal";
            else if (cnt == 3) ret[j] = "Bronze Medal";
            else ret[j] = to_string(cnt);
        }
        
        return ret;
    }
};