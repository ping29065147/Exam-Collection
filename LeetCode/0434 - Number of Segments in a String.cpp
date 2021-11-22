static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countSegments(string s)
    {
        stringstream ss(s);
        int cnt = 0;
        string tmp;
        
        while(ss >> tmp) ++cnt;
        return cnt;
    }
};