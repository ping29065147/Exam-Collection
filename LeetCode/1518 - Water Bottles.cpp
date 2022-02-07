static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int cnt = numBottles, emptyBottles = numBottles;
        
        while(emptyBottles >= numExchange)
        {
            numBottles = emptyBottles / numExchange;
            cnt += numBottles;
            emptyBottles = emptyBottles % numExchange + numBottles;
        }
        
        return cnt;
    }
};