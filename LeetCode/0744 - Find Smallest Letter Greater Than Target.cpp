static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        for (auto& c : letters) if (target < c) return c;
        return letters[0];
    }
};