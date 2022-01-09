static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> PQ;
        
        for (auto& i : stones) PQ.push(i);
        while(PQ.size() > 1)
        {
            int a = PQ.top(); PQ.pop();
            int b = PQ.top(); PQ.pop();
            if (a != b) PQ.push(abs(a - b));
        }
        
        return PQ.empty() ? 0 : PQ.top();
    }
};