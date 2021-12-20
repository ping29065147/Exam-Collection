static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string toGoatLatin(string sentence)
    {
        unordered_map<char, bool> M = {{'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true}, {'A', true}, {'E', true}, {'I', true}, {'O', true}, {'U', true}};
        stringstream ss(sentence);
        string ret, str;
        
        for (int cnt = 0; ss >> str; ++cnt)
        {
            if (cnt) ret += " ";
            
            if (M[str[0]]) ret += str + "ma";
            else ret += str.substr(1) + str[0] + "ma";
            
            for (int i = 0; i <= cnt; ++i) ret += "a";   
        }
        
        return ret;
    }
};