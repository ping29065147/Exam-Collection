static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string gcdOfStrings(string str1, string str2)
    {
        return (str1 + str2 == str2 + str1) ? str1.substr(0, gcd(str1.size(), str2.size())) : "";
    }
};