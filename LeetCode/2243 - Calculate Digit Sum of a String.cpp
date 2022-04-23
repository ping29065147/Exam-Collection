static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string digitSum(string s, int k)
    {
        string t;
        int n = 0;
        
        while(s.size() > k)
        {
            string new_s;
            for (int i = 0; i < s.size(); i += k)
            {
                int n = 0;                             
                t = s.substr(i, k);
                for (auto& c : t) n += (c - '0');
                new_s += to_string(n);
            }
            s = new_s;
        }        
        
        return s;
    }
};