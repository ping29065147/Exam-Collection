static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k)
    {
        int cnt = 0;
        int num = tickets[k];
        
        for (int i = 0; i < tickets.size(); ++i)
        {
            if (i == k + 1) --num;
            cnt += min(num, tickets[i]);
        }
        
        return cnt;
    }
};