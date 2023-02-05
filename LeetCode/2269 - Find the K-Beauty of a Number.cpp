static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int divisorSubstrings(int num, int k)
    {
        int ans = 0;
        string s = to_string(num);

        for (int i = 0; i <= s.size() - k; ++i)
        {
            string t = s.substr(i, k);
            if (stoi(t)) ans += (num % stoi(t) == 0);
        }

        return ans;
    }
};