static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isHappy(int n)
    {
        unordered_map<int, bool> M;
        
        while(!M[n] && n != 1)
        {
            M[n] = true;
            int new_n = 0;
            while(n != 0) new_n += pow(n % 10, 2), n /= 10;
            n = new_n;
        }
        
        return n == 1;
    }
};