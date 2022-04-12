static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minimumSum(int num)
    {
        vector<int> V;
        int cnt = 0;
        int x = 1, t = 0;
        
        while(num) V.push_back(num % 10), num /= 10;
        sort(V.begin(), V.end(), greater<int>());
        for (auto& i : V)
        {
            if (!i) continue;
            
            cnt += i * x;
            if (++t == 2) x *= 10, t = 0;
        }
        
        return cnt;
    }
};