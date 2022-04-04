static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countValidWords(string sentence)
    {
        stringstream ss(sentence);
        string str;
        int cnt = 0;
        
        while(ss >> str)
        {
            bool valid = true;
            int cnt2 = 0;
            
            for (int i = 0; i < str.size() && valid; ++i)
            {
                if (isdigit(str[i])) valid = false;
                else if (str[i] == '-')
                {
                    if (i == 0 || i == str.size() - 1) valid = false;
                    else if (++cnt2 == 2) valid = false;
                    else if (!isalpha(str[i - 1]) || !isalpha(str[i + 1])) valid = false;
                }
                else if (str[i] == '!' || str[i] == '.' || str[i] == ',')
                {
                    if (i != str.size() - 1) valid = false;
                }
            }
            
            cnt += valid;
        }
        
        return cnt;
    }
};