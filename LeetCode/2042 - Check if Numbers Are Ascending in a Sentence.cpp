static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool areNumbersAscending(string s)
    {
        stringstream ss(s);
        string str;
        int cur = 0;
        
        while(ss >> str)
        {
            if (all_of(str.begin(), str.end(), [](char c){ return isdigit(c); })) 
            {
                if (stoi(str) <= cur) return false;
                cur = stoi(str);
            }
        }
        
        return true;
    }
};