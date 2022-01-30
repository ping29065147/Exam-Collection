static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        stringstream ss(sentence);
        string str;
        int cnt = 0;
        
        while(ss >> str)
        {
            ++cnt;
            if (str.find(searchWord) == 0) return cnt;
        }
        
        return -1;
    }
};