static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool checkZeroOnes(string s)
    {
        int ones = 0, zeros = 0;  
        
        for (int i = 0; i < s.size();)
        {
            int cnt = 1;
            if (s[i] == '1')
            {
                while(s[++i] == '1') ++cnt;
                ones = max(ones, cnt);
            }
            else
            {
                while(s[++i] == '0') ++cnt;
                zeros = max(zeros, cnt);
            }
        }
        
        return ones > zeros;
    }
};