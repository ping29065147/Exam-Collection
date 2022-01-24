static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string sortString(string s)
    {
        map<char, int> M;
        string ret;
        
        for (auto& c : s) ++M[c];
        while(ret.size() != s.size())
        {
            for (auto& [i, j] : M) if (j > 0) ret.push_back(i), --j;
            for (auto i = M.rbegin(); i != M.rend(); ++i)
            {
                if (i->second > 0)
                {           
                    ret.push_back(i->first);
                    --i->second;
                }
            }
        }
        
        
        return ret;
    }
};