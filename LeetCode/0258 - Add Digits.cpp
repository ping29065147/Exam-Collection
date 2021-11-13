static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int addDigits(int num)
    {
        while(num >= 10)
        {
            int tmp = 0;
            while(num != 0) tmp += num % 10, num /= 10;
            num = tmp;
        }
        
        return num;
    }
};