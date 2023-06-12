static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience)
    {
        int ans = 0, cnt = 0;

        for (auto& i : energy) cnt += i;
        if (cnt >= initialEnergy) ans = cnt - initialEnergy + 1;

        for (auto& i : experience)
        {
            if (initialExperience <= i)
            {
                ans += (i - initialExperience + 1);                
                initialExperience = i + 1;
            }
            initialExperience += i;
        }

        return ans;
    }
};