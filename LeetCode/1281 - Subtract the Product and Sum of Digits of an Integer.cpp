static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int subtractProductAndSum(int n)
    {
        int pdt = 1;
        int sum = 0;
        
        while(n)
        {
            pdt *= n % 10;
            sum += n % 10;
            n /= 10;
        }
        
        return pdt - sum;
    }
};