static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words)
    {
        for (int i = 1; i < words.size(); ++i)
        {
            string t1 = words[i];
            string t2 = words[i - 1];
            sort(t1.begin(), t1.end());
            sort(t2.begin(), t2.end());
            if (t1 == t2) words.erase(words.begin() + i), --i;
        }

        return words;
    }
};