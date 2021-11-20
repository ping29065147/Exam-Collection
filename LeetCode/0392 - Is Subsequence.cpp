static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int ptr_s = 0, ptr_t = 0;
        int sizeS = s.size(), sizeT = t.size();
        
        while(ptr_t < sizeT)
        {
            if (ptr_s == sizeS) return true;
            
            if (s[ptr_s] == t[ptr_t]) ++ptr_s;
            ++ptr_t;
        }
        
        return ptr_s == sizeS;
    }
};