static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minCostToMoveChips(vector<int>& position)
    {
        int cnt = 0;
        int n = position.size();
        
        for (auto& i : position) 
        {
            i %= 2;
            cnt += i;
        }
        
        return min(cnt, n - cnt);
    }
};