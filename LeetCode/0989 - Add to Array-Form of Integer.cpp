static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k)
    {
        int it = num.size() - 1;
        
        while(k)
        {
            if (it < 0)
            {
                num.insert(num.begin(), 0);
                it = 0;
            }
            num[it--] += k % 10;
            k /= 10;
        }
        
        for (it = num.size() - 1; it >= 0; --it)
        {
            if (num[it] >= 10)
            {
                num[it] -= 10;
                if (it - 1 < 0) num.insert(num.begin(), 1);
                else ++num[it - 1];
            }
        }

        
        return num;
    }
};