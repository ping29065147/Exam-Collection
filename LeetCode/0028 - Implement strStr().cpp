static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int hSize = haystack.size();
        int nSize = needle.size();
        
        if (!nSize) return 0;
        if (nSize > hSize) return -1;
        
        for (int i = 0; i <= hSize - nSize; ++i)
            if (haystack.substr(i, nSize) == needle) return i;
                
        return -1;
    }
};