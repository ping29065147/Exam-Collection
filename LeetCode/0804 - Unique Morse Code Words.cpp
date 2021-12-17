static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        unordered_map<string, int> M;
        string table[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for (auto& word : words)
        {
            string str;
            
            for (auto& c : word) str += table[c - 'a'];           
            ++M[str];
        }
        
        return M.size();
    }
};