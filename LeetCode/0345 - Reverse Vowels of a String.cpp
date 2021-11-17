static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string reverseVowels(string s)
    {
        int l = 0;
        int r = s.size() - 1;
        unordered_map<char, bool> M{{'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true}, {'A', true}, {'E', true}, {'I', true}, {'O', true}, {'U', true}};
        
        while(l < r)
        {
            if(!M[s[l]]) ++l;
            else if(!M[s[r]]) --r;
            else swap(s[l++], s[r--]);
        }
        
        return s;
    }
};