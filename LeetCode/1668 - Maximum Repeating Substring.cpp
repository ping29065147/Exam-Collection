static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxRepeating(string sequence, string word)
    {
        string s = word;
        int cnt = 0;
        
        while(sequence.find(s) != string::npos)
        {
            ++cnt;
            s += word;
        }
        
        return cnt;
    }
};