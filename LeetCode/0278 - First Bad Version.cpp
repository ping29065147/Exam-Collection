// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int firstBadVersion(int n)
    {
        int l = 1;
        
        while(l < n)
        {
            int m = l + (n - l) / 2;
            if (isBadVersion(m)) n = m;
            else l = m + 1;
        }
        
        return l;
    }
};