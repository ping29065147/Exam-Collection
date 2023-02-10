static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int rearrangeCharacters(string s, string target)
    {
        unordered_map<char, int> M;
        int ans = 0;

        for (auto& c : s) ++M[c];
        while(1)
        {
            for (auto& i : target)
                if (--M[i] < 0)
                    return ans;
            ++ans;
        }

        return ans;
    }
};