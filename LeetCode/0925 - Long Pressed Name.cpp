static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isLongPressedName(string name, string typed)
    {
        int i = 0, j = 0;
        char pre = ' ';
        
        while(i < name.size() || j < typed.size())
        {
            if (name[i] == typed[j]) ++j, pre = name[i++];
            else if (typed[j] == pre) ++j;
            else return false;
        }
        
        return true;
    }
};