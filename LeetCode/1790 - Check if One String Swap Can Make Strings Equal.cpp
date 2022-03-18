static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int it = -1;
        
        for (int i = 0; i < s1.size(); ++i)
        {
            if (s1[i] != s2[i])
            {
                if (it == -1) it = i;
                else
                {
                    swap(s1[it], s1[i]);
                    break;
                }
            }
        }
        
        return s1 == s2;
    }
};