static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string addStrings(string num1, string num2)
    {
        string ret;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        
        while(i >= 0 || j >= 0)
        {
            int a = (i >= 0 ? num1[i--] - '0' : 0);
            int b = (j >= 0 ? num2[j--] - '0' : 0);
            int sum = a + b + carry;
            ret.insert(ret.begin(), sum % 10 + '0');
            carry = sum / 10;
        }
        
        return carry ? "1" + ret : ret;
    }
};