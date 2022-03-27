static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string largestOddNumber(string num)
    {
        while(!num.empty() && (num.back() - '0') % 2 == 0) num.pop_back();  
        return num.empty() ? "" : num;
    }
};