static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ret;
        
        for (int i = 1; i <= n; ++i)
        {
            if (i % 5 == 0 && i % 3 == 0) ret.push_back("FizzBuzz");
            else if (i % 5 == 0) ret.push_back("Buzz");
            else if (i % 3 == 0) ret.push_back("Fizz");
            else ret.push_back(to_string(i));
        }
        
        return ret;
    }
};