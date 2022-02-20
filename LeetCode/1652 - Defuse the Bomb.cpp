static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k)
    {
        int s = code.size();
        int add;
        vector<int> ret(s);
        
        if (!k) return vector<int>(s, 0);
        
        if (k > 0) add = 1;
        else add = s - 1;
          
        for (int i = 0; i < s; ++i)
        {
            int cnt = 0, p = i;

            for (int j = 0; j < abs(k); ++j)
            {
                p = (p + add) % s;
                cnt += code[p];
            }

            ret[i] = cnt;
        }
        
        return ret;
    }
};