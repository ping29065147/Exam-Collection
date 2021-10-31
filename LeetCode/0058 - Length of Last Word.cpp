static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int lengthOfLastWord(string s)
    {
        string word;
        stringstream ss(s);    
        while(ss >> word) ;
        
        return word.size();
    }
};