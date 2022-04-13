static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countOperations(int num1, int num2)
    {
        int cnt = 0;
        
        while(num1 && num2)
        {
            num1 >= num2 ? num1 -= num2 : num2 -= num1;
            ++cnt;
        }
        
        return cnt;
    }
};