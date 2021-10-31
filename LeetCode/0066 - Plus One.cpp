static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        ++digits[digits.size() - 1];
        for (int i = digits.size() - 1; i >= 0; --i) if (digits[i] == 10)
        {
            digits[i] -= 10;
            
            if (i != 0) ++digits[i - 1];
            else
            {   
                digits.push_back(0);
                rotate(digits.begin(), digits.begin() + 1, digits.end());
                ++digits[0];
            }
        }
        
        return digits;
    }
};